/*Riley Brandau
 * CS344 - Program 3 - smallsh
 * Due 3/5/17 (pushed back from 3/3/17)
 * Description: This program creates a simple shell that supports three
 *              commands: exit, cd, and status. It will also support
 *              comments: lines that start with a '#' character.
 * General syntax for use:
 *              command [arg1 arg2...] [< input_file] [> output_file] [&]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

//Defining some global constants
#define MAX_ARGS 512
#define MAX_CHARS 2048


//Defining symbol flag struct
typedef struct
{
   int background_process;                 //handles background '&'
   int redir_in;                           //handles input redirection '<'
   int redir_out;                          //handles output redirection '>'
}Flags;

Flags flagStruct;


//Prototypes
void catch_interrupt(int signo);
void cmd_input();
void check_background();
//void set_sigStructs();
//void reset_flags();

//Defining some global variables
int background_pids[64];                   //holds background process ids
int num_processes;                         //keeps track of background processes
char MAX_ARG_ARR[512];                     //array for holding arguments/commands
int exit_status = 0;                       //process exit status



int main(int argc, char *argv[])
{
   int file_descriptor;                      //used for redirecting
   
   int status = 0;                         //variable for status changes
   int conRun = 1;                         //run the shell while this is true
   //set_sigStructs();
   //create and initialize initial sigaction struct
   struct sigaction initial_action;
   initial_action.sa_handler = catch_interrupt;
   initial_action.sa_flags = 0;

   //create and initialize foreground sigaction struct
   struct sigaction foreG_action;        
   foreG_action.sa_handler = catch_interrupt;
   foreG_action.sa_flags = 0;
   sigfillset(&(foreG_action.sa_mask));
   sigaction(SIGINT, &foreG_action, NULL);

   //create and initialize background sigaction struct
   struct sigaction backG_action;
   backG_action.sa_handler = catch_interrupt;
   backG_action.sa_flags = 0;
   sigfillset(&(backG_action.sa_mask));
   sigaction(SIGINT, &backG_action, NULL);

   //create meanwhile sigaction struct
   struct sigaction meanwhile_action;
   sigaction(SIGINT, &initial_action, &meanwhile_action);

   while(conRun)                                                   //runs the shell while true
   {
      //To be done at each iteration
      sigaction(SIGINT, &initial_action, &meanwhile_action);
      sigaction(SIGINT, &backG_action, NULL);
      sigaction(SIGINT, &foreG_action, NULL);
      check_background();                                          //checking if anything is running in bhe background
      cmd_input();                                                 //for user input

      //Built in Functions: Comments
      if(strncmp(MAX_ARG_ARR, "#", 1) == 0)                        //ignores comments (designated by the '#' character)
      {
         continue;
      }
      //Built in Functions: Exit
      if(strcmp(MAX_ARG_ARR, "exit") == 0)                        //chcking for exit command
      {
         conRun = 0;                                               //ends the loop
      }   
      //Built in Functions: Status
      else if(strcmp(MAX_ARG_ARR, "status") == 0)                 //for checking status command
      {
         status = WEXITSTATUS(status);                             //gets the exit status
         printf("Exit value: %d\n", status);
      }
      else if(strcmp(MAX_ARG_ARR, "test_test") == 0)              //test command
      {
         status = 1;
      }
      //Built in Functions: CD
      else if (strncmp("cd", MAX_ARG_ARR, 2) == 0)                 //checking for cd command
      {
         char curDir[1024];
         char source[32];
         char *homeDir;
         int sourceLen = 0;
         int i = 0;

         getcwd(curDir, sizeof(curDir));                           //get the current working directory
         strcpy(source, MAX_ARG_ARR);                              //get directory to move to                 
         sourceLen = strlen(source); 

         if(sourceLen > 2)
         {
            sourceLen = sourceLen - 3;                             //moving past the cd index
            char temp[32];                                         //for storing index
            for(i = 0; i < sourceLen; i++)
            {
               temp[i] = source[i + 3];
            }
            
            strcpy(source, temp);                                  //store source in temp
            strcat(curDir, "/");                                   //add a / to the path
            strcat(curDir, source);                                //build the path
            chdir(curDir);                                         //move into new folder
         }
         else
         {
            homeDir = getenv("HOME");                              //move into home dir if just 'cd'
            chdir(homeDir);
         }
      }
      else                                                         //no longer built in commands                                             
      {
         char *cmdArr[MAX_ARGS];
         char *cmd;
         const char spaces[] = " ";
         int userCmds = 1;
         pid_t spawnpid;                                           //spawning new process
         cmd = strtok(MAX_ARG_ARR, spaces);                        //add commands/arguments to array separated by spaces
         cmdArr[0] = cmd;                                          //first command
         cmdArr[userCmds] = strtok(NULL, spaces);      
         
         while(cmdArr[userCmds] != NULL)                           //loop through unprocessed commands
         {
            userCmds += 1;                                         //increase user command count
            cmdArr[userCmds] = strtok(NULL, spaces);               //queue next command
         }
         
         if(flagStruct.background_process == 1)                          //checking background process
         {
            spawnpid = fork();                                     //spawn process in background
            if(spawnpid < 0)
            {
               perror("Forking Error.");
               exit(1);
            }
            if(spawnpid == 0)                                      //child process
            {
               int j = 0;
               for(j = 0; j < userCmds; j++)
               {
                  if(flagStruct.redir_in == 1)                     //flag redirection
                  {
                     file_descriptor = open(cmdArr[userCmds + 2], O_RDONLY, 0);
                     if(file_descriptor == -1)                                             //error for opening
                     {
                        printf("Unable to open %s for input\n", cmdArr[userCmds + 1]);
                        exit(1);
                     }
                     else                                                                  //No errors, execute
                     {
                        dup2(file_descriptor, STDIN_FILENO);                               //redirect standard input
                        close(file_descriptor);                                            //close file
                        execvp(cmd, &cmd);                                                 //execute the command
                     }
                  }
                  if(flagStruct.redir_out == 1)
                  {
                     file_descriptor = creat(cmdArr[userCmds + 2], 0644);                  //Trying to create a file for command and set permissions
                     if(file_descriptor == -1)
                     {
                        printf("Unable to open %s for input\n", cmdArr[userCmds + 1]);
                        exit(1);
                     }
                     else                                                                  //success -> execute
                     {
                        dup2(file_descriptor, STDOUT_FILENO);                              //redirect standard output
                        close(file_descriptor);                                            //close the file
                        execvp(cmd, &cmd);                                                 //execute the command
                     }
                  }
               }
               if(flagStruct.redir_in == 0 && flagStruct.redir_out == 0)                   //no redirection
               {
                  execvp(cmd, cmdArr);                                                     //execute the command
               }
               else                                                                        //command not found
               {
                  printf("File or directory not found: %s\n", cmd);
               }
            }
            else                                                                           //track background processes and add them into an array
            {
               int status_1;
               int process;
               printf("Background Process ID: %d\n", spawnpid);
               background_pids[num_processes] = spawnpid;
               num_processes += 1;
               process = waitpid(spawnpid, &status_1, WNOHANG);
               continue;
            }
         }
         else                                                                              //foreground processes
         {
            spawnpid = fork();                                                             //spawn foreground process
            if(spawnpid < 0)
            {
               perror("Forking Error.");
               exit(1);
            }
            if(spawnpid == 0)                                                              //child process
            {
               int j = 0;
               for (j = 0; j < userCmds; j++)
               {
                  if(flagStruct.redir_in == 1)                                             //read the file, or print an error
                  {
                     file_descriptor = open(cmdArr[j + 2], O_RDONLY, 0);
                     if(file_descriptor == -1)
                     {
                        printf("Unable to open %s for input\n", cmdArr[j + 2]);
                        exit(1);
                     }
                     else                                                                  //success -> execute
                     {
                        dup2(file_descriptor, STDIN_FILENO);                               //redirect standard input
                        close(file_descriptor);                                            //close file
                        execvp(cmd, &cmd);                                                 //execute the command
                     }
                  }
                  if(flagStruct.redir_out == 1)                                            //Create the file with permissions, or print an error if unsuccessful
                  {
                     file_descriptor = creat(cmdArr[j + 2], 0644);
                     if(file_descriptor == -1)
                     {
                        printf("Unable to open %s for input\n", cmdArr[j + 2]);
                        exit(1);
                     }
                     else                                                                  //success -> execute
                     {
                        dup2(file_descriptor, STDOUT_FILENO);                              //redirect standard output
                        close(file_descriptor);                                            //close the file
                        execvp(cmd, &cmd);                                                 //execute the command
                     }
                  }
               }
               if(flagStruct.redir_in == 0 && flagStruct.redir_out == 0)                   //no redirection, just a command
               {
                  execvp(cmd, cmdArr);
               }
               else
               {
                  printf("File or directory not found: %s\n", cmd);
               }
            }
            else
            {
               int status_exit;
               waitpid(spawnpid, &status, 0);
               if(WIFEXITED(status_exit))
               {
                  exit_status = WEXITSTATUS(status_exit);
               }
            }
         }
      } 
      //reset the flags for the next pass through
      //reset_flags();
      flagStruct.background_process = 0;
      flagStruct.redir_in = 0;
      flagStruct.redir_out = 0;
      signal(SIGINT, SIG_IGN);
   }
   return 0;
}
 

//***********FUNCTIONS************



//This function captures and displays user signals                 
void catch_interrupt(int signo)
{
   printf("Program terminated by signal: %d\n", signo);
}


//This function flushes the input and output and
//determines if a process should be run in the background
void cmd_input()
{
   fflush(stdin);                                                 //flushing stdin
   fflush(stdout);                                                //flushing stdout
   printf(": ");                                                  //printing a colon and a space
   fflush(stdin);                                                 //flushing stdin again

   if(fgets(MAX_ARG_ARR, sizeof(MAX_ARG_ARR), stdin) != NULL)
   {
      char *temp;
      temp = strchr(MAX_ARG_ARR, '\n');                           //search for a newline char
      *temp = '\0';                                               //set it to null char
      flagStruct.background_process = 0;                          //set background process to 0

      if((temp = strchr(MAX_ARG_ARR, '&')) != NULL)               //if not null, set background process
      {
         *temp = '\0';                                            //replace the & with a null char
         flagStruct.background_process = 1;
      }
      if((temp = strchr(MAX_ARG_ARR, '<')) != NULL)               //if not null, set input flag
      {
         flagStruct.redir_in = 1;
      }
      if((temp = strchr(MAX_ARG_ARR, '>')) != NULL)               //if not null, set output flag
      {
         flagStruct.redir_out = 1;
      }
   }
}


//This function is used to check background processes and their status
void check_background()
{
   int status;
   int i;
   for(i = 0; i < num_processes; i++)                           //loops through background processes array
   {
      if(waitpid(background_pids[i], &status, WNOHANG) > 0)     //If a child process is found
      {
         if(WIFEXITED(status))                                  //exit status
         {
            printf("Background Process #: %d has finished. Exiting with value: %d\n", background_pids[i], WEXITSTATUS(status));
         }
         if(WIFSIGNALED(status))                                //termination status
         {
            printf("Background Process: %d was terminated. Terminated by signal: %d\n", background_pids[i], WTERMSIG(status));                     
         }
      }
   }
}


//This function sets up the SIGACTION structs
/*
void set_sigStructs()
{
   struct sigaction foreG_action;
   struct sigaction backG_action;
   struct sigaction initial_action;
   struct sigaction meanwhile_action;

   foreG_action.sa_handler = catch_interrupt;
   backG_action.sa_handler = catch_interrupt;
   initial_action.sa_handler = catch_interrupt;
   
   foreG_action.sa_flags = 0;
   backG_action.sa_flags = 0;
   initial_action.sa_flags = 0;
   
   sigfillset(&(foreG_action.sa_mask));
   sigfillset(&(backG_action.sa_mask));
   sigfillset(&(initial_action.sa_mask));

   sigaction(SIGINT, &foreG_action, NULL);
   sigaction(SIGINT, &backG_action, NULL);
   sigaction(SIGINT, &initial_action, &meanwhile_action);  
}
*/

//This function resets the flagStruct's flags
/*
void reset_flags()
{
   flagStruct.background_p = 0;
   flagStruct.redir_in = 0;
   flagStruct.redir_out = 0;
}
*/
