#Riley Brandau
#CS 344
#Due: 3/10/17
#Description: Upon execution, this script creates 3 files in the same
#             directory as mypython.py. Each file will have a different
#             name. Each file will contain exactly 10 random lowercase
#             characters, the 11th character being a newline char.
#             It should print out the contents of the 3 files (not 
#             necessarily reading the file's contents). It will aslo
#             print two random integers between 1-42 and the product
#             of those integers.
#
#To Compile/Run: python mypython.py


import string
import random

print("\n")
print("Generating Three Files with 10 random lowercase letters...\n")

lowCaseLetters = ""
letters = []
numX = 0
numY = 0
XY = 0

for i in range(0,3):                                                                 #used for creating 3 files
   for j in range(0,10):                                                             #used for generating 10 letters
      lowCaseLetters = lowCaseLetters + str(random.choice(string.ascii_lowercase))   #generate a random lowercase letter
   
   letters.append(lowCaseLetters)                                                    #add the letter to an array
   newFile = "file_num_" + str(i+1) + ".txt"                                         #generate a new text file
   f_out = open(newFile, "w")                                                        #open the new file for writing
   f_out.write(letters[i] + "\n")                                                    #write the lowercase letters + newline char
   f_out.close()                                                                     #close the file\

   print("Contents of File#" + str(i+1) +  ": " + letters[i])                        #print file contents to screen
   lowCaseLetters = ""                                                               #clear variable for next loop

print("\n")
numX = random.randint(1,42)                                                          #generate a rand num between 1 & 42
numY = random.randint(1,42)
XY = numX * numY                                                                     #calculate the product

print("Generating Random Numbers...")
print("X = " + str(numX))                                                            #print the results & product
print("Y = " + str(numY))
print(str(numX) + "*" + str(numY) + " = " + str(XY))
print("\n")

