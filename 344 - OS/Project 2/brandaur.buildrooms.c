/*
 * Name: Riley Brandau
 * Class: CS_344
 * Program: brandaur.buildrooms.c
 * Due Date: 2/13/17
 * Description: This program creates a directory and generates rooms (files) that will be used in brandaur.adventure.c
 * */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>


//Defining some global constants
#define MIN_ROOM_CONNECTIONS 3
#define MAX_ROOM_CONNECTIONS 6
#define NUM_OF_ROOMS 7


//Struct that will hold all of the room's information
struct Room
{
   const char *name;                                           //name of room
   const char *roomType;                                       //type of room (start, mid, end)
   int maxCon;                                                 //maximum number of connections
   int curCon;                                                 //current number of connections
   struct Room *connectedRooms[MAX_ROOM_CONNECTIONS];          //stores the rooms that this room is connected to
};

//Prototypes
void createDir();
void genRooms(int *randRoom, int *connections);
void createRooms(int *randRoom, int *connections, struct Room **roomArray);
void connectRooms(struct Room **roomArray);
void roomToFile(struct Room **roomArray);
void sortRooms(struct Room **rooms);
void releaseRooms(struct Room **rooms);


//array that holds possible room names (Jurassic Park themed)
const char *roomNames[] = {
   "Visitor_Center",
   "Gallimimus_Valley",
   "AVIARY",
   "T.REX_PEN",
   "Velociraptor_Paddock",
   "Triceratops_Territory",
   "Dilophosaurus_Den",
   "The_River",
   "The_Dock",
   "The_Waterfall",
};



int main()
{
   //printf("Initializing random seed"); //debug
   srand(time(NULL));                                           //Call srand() to initialize random seed
   //printf("Initializing variables");
   //Set up some variables for rooms
   int rooms[NUM_OF_ROOMS];                                     //Holds room indices
   int connections[NUM_OF_ROOMS];                               //Holds connections for each room
   struct Room *roomArray[NUM_OF_ROOMS];                        //Holds rooms
   //printf("Creating directory"); //debug
   createDir();                                                 //Create the directory to store rooms
   //printf("Generating rooms"); //debug
   genRooms(rooms, connections);                                //Generate the room names and how they connect to other rooms
   //printf("Creating rooms"); //debug
   createRooms(rooms, connections, roomArray);                  //Creates the rooms
   //printf("Sorting rooms"); //debug
   sortRooms(roomArray);                                        //Sorting rooms by their number of connections
   //printf("Connecting rooms"); //debug
   connectRooms(roomArray);                                     //Connect rooms together
   //printf("Writing rooms to files"); //debug
   roomToFile(roomArray);                                       //Write the rooms to files
   //printf("freeing memory"); //debug
   releaseRooms(roomArray);                                     //Free up memory

   return 0;
}


/*
 * Creates a directory to store generated room files
*/
void createDir()
{
   int process = getpid();                                      //Get the process' ID
   char directory[] = "brandaur.rooms.";                        //Format for directory naming <username>.rooms
   char pathName[0];                                            //Stores directory path name
   sprintf(pathName, "%s%d", directory, process);               //Append process ID to directory name to create path
   mkdir(pathName, 0755);                                       //Create the directory and allow access

   chdir(pathName);                                             //***Changes directory to freshly created one***
}


/*
 * Generate the room names and connections
*/
void genRooms(int *randRoom, int *connections)
{
   int roomIndex = 0;
   int counter = 0;
   do{
      int randNum = rand() % 10;
      int randCon = 0;
      int current = 0;
      int i = 0;
      //Check to see if the room was already selected
      for(i = 0; i < roomIndex; i++)
      {
         if(randRoom[i] == randNum)
         {
            current = 1;
         }
      }
  
      //Place room into array if it is not a duplicate
      if(current == 0)
      {
         randRoom[roomIndex] = randNum;
         randCon = (rand() % (MAX_ROOM_CONNECTIONS - MIN_ROOM_CONNECTIONS + 1)) + MIN_ROOM_CONNECTIONS;
      /*
       * Creates and checks connections between rooms. If a room has six connections,
       * that means it is connected to all other rooms (three, six connection rooms
       * are possible). Since each room has to be connected to rooms that are connected
       * to it, we need to check the number of connections to make sure it's doable.
      */
         if(randCon == 6) 
         {
            if(counter == 3)
            {
               while(randCon == 6)
               {
                  randCon = (rand() % (MAX_ROOM_CONNECTIONS - MIN_ROOM_CONNECTIONS + 1)) + MIN_ROOM_CONNECTIONS;
               }
            }
            else
            {
               counter++;
            }
         }
         connections[roomIndex] = randCon;
         roomIndex++;   
      }
  }while(roomIndex < NUM_OF_ROOMS);
}


/*
 * Creates the rooms, assigns the rooms their information (name, connections, type)
 * and stores them in an array
*/
void createRooms(int *randRoom, int *connections, struct Room **roomArray)
{
   int i = 0;
   for(i = 0; i < NUM_OF_ROOMS; i++)
   {
      struct Room *dungeon = malloc(sizeof(struct Room));       //Create a structure to hold all of the room's information
      dungeon->name = roomNames[randRoom[i]];                   //Assign a name to the room
      dungeon->maxCon = connections[i];                         //Assigns the maximum amound of connections the room can have            
      dungeon->curCon = 0;                                      //Initialize current connections to zero

      if(i == 0)                                                //If i equals zero, it makes that room the starting room (only one)
         {
            dungeon->roomType = "START_ROOM";
         }
      else if(i == (NUM_OF_ROOMS - 1))                          //If i equals (NUM_OF_ROOMS - 1), in this case, 6, it is the final room
         {
            dungeon->roomType = "END_ROOM";
         }
      else                                                      //Otherwise, all the other rooms are middle rooms
         {
            dungeon->roomType = "MID_ROOM";
         }
      roomArray[i] = dungeon;                                   //Store the room in the array.
   }
}


/*
 * Creates the connections between the rooms
*/
void connectRooms(struct Room **roomArray)
{  
   int i = 0;
   int j = 0;
   for(i = 0; i < NUM_OF_ROOMS; i++)
   {
      if(roomArray[i]->maxCon == 6)                                                    //If a room has 6 connections
      {
         for(j = i + 1; j < NUM_OF_ROOMS; j++)
         {
            roomArray[i]->connectedRooms[roomArray[i]->curCon] = roomArray[j];         //create connections between the rooms
            roomArray[j]->connectedRooms[roomArray[j]->curCon] = roomArray[i];         //create connections between the rooms
            roomArray[i]->curCon++;                                                    //increase the counter for connected rooms
            roomArray[j]->curCon++;                                                    //increase the counter for connected rooms
         }
      }
      else                                                                             //If a room has less than 6 connections
      {
         if(roomArray[i]->maxCon > roomArray[i]->curCon)                               //If there are still possible connections available
         {
            for(j = i + 1; j < NUM_OF_ROOMS; j++)
            {
               if(roomArray[j]->maxCon > roomArray[j]->curCon)                         //If there are still possible connections available
               {
                  roomArray[i]->connectedRooms[roomArray[i]->curCon] = roomArray[j];   //create connections between the rooms
                  roomArray[j]->connectedRooms[roomArray[j]->curCon] = roomArray[i];   //create connections between the rooms
                  roomArray[i]->curCon++;                                              //increase the counter for connected rooms
                  roomArray[j]->curCon++;                                              //increase the counter for connected rooms
               }
            }
            if(roomArray[i]->maxCon < roomArray[i]->curCon)                            //Set rooms max connections to it's current connections
            {                                                                          //if there are no more available connections
               roomArray[i]->maxCon = roomArray[i]->curCon;
            }
         }
      }
   }
}


/*
 * Handles creating the room files and populating them with room information
*/
void roomToFile(struct Room **roomArray)
{
   const char *roomName;
   int i = 0;
   int j = 0;
   for(i = 0; i < NUM_OF_ROOMS; i++)
   {
      roomName = roomArray[i]->name;                                                           //Get the name from the array of rooms
      FILE *writeTo = fopen(roomName, "w");                                                    //create a file with the room name and give write permission
      
      if(writeTo == NULL)                                                                       //check if file opened correctly
      {
         printf("Error opening file...");
         exit(1);
      }
  
      fprintf(writeTo, "ROOM NAME: %s\n", roomArray[i]->name);                                  //Write the room name to the file

      for(j = 0; j < roomArray[i]->curCon; j++)                                                 //Write all of the room's connections to the file
      {
         fprintf(writeTo, "CONNECTION %d: %s\n", j + 1, roomArray[i]->connectedRooms[j]->name);
      }
      
      fprintf(writeTo, "ROOM TYPE: %s\n", roomArray[i]->roomType);                              //Write the room's type to the file
      fclose(writeTo);
   }
}


/*
 * Iterate through the rooms and free up memory
*/
void releaseRooms(struct Room **rooms)
{
   int i = 0;
   for(i = 0; i < sizeof(rooms) - 1; i++)
   {
      free(rooms[i]);
   }
}


/*
 * Sorts the rooms by connections so that they are connected properly.
 * (ie, connect all the rooms w/ 6 connections first)
*/
void sortRooms(struct Room **rooms)
{
   int index = 0;
   int indexCons = 0;
   struct Room *temp;
   int i = 0;
   int j = 0;
   for(i = 0; i < NUM_OF_ROOMS - 1; i++)
   {
      index = i;
      indexCons = rooms[i]->maxCon;
      temp = rooms[i];

      for(j = i + 1; j < NUM_OF_ROOMS; j++)
      {
         if(rooms[j]->maxCon > indexCons)
         {
            indexCons = rooms[j]->maxCon;
            index = j;
         }
      }
      
      temp = rooms[index];
      rooms[index] = rooms[i];
      rooms[i] = temp;
   }
} 
