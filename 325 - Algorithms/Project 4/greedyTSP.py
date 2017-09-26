#Riley Brandau, Ian O'Leary, Matthew Yates
#CS 325 - Project 4
#Due: 3/17/17 
#Description:     Uses a greedy(nearest neighbor) algorithm to determine a near optimal tour
#                 from a graph provided in a file with the structure [id][x_coord][y_coord]
#                       
# To run:           python greedyTSP.py filename.txt


import math
import os
import sys
import time

#Defining the function that calculates the cartesian distance between two cities
def cartesianDist(cityA, cityB):
	distX = cityA['x'] - cityB['x']
	distY = cityA['y'] - cityB['y']
	distXsq = math.pow(distX, 2)
	distYsq = math.pow(distY, 2)
	result = math.sqrt(distXsq + distYsq)
	result = int(round(result))
	return result

#Defining main()	
def main():
	if (len(sys.argv) != 2):                                                   #terminate if an argument is not passed
		print ('ERROR: Expected one argument to be passed...\n')
		quit()
	else:
		inputFile = sys.argv[1]                                            #assign file name to variable
		if not(os.path.isfile(inputFile)):                                 #terminate if file can't be opened
			print ('ERROR: unable to open file\n')
			quit()

	
	filePath = os.path.basename(inputFile)                                     #store file path
	inputFile = open(filePath, 'r')                                            #open input file

	citiesA = []                                                               #stores input file city info
	for eachRow in inputFile:
		everyCity = eachRow.split()                                        #read line by line
		currentCity = {'ID':int(everyCity[0]), 'x':int(everyCity[1]), 'y':int(everyCity[2])}      #store data
		citiesA.append(currentCity)                                        #add to list
		
	inputFile.close()                                                          #close input file

	cityMatrix = [[-1 for x in range(len(citiesA))] for y in range(len(citiesA))]                     #initialize city matrix
	
	startTime = time.time() 
	tour_min_dist = sys.maxsize                                                #set the minimum tour distance
	tour_min_order = []                                                        #for storing the optimal tour order
	for i in range(0, len(citiesA)):
		tour_distance = 0                                                  #loop tour distance
		tour_order = []                                                    #loop tour order
		citiesB = [x for x in citiesA]                                     #copy cities into another list
		tour_order.append(citiesB[i]['ID'])                                #add cities by ID to loop tour order
		citiesB.remove(citiesB[i])                                         #remove the city from the list
		
		while len(citiesB) > 0:                                            #loop for determining distances
			currentCity = citiesA[tour_order[len(tour_order) - 1]]
			current_min_dist = sys.maxsize                             
			current_min_city = -1
			for j in range(0, len(citiesB)):                           #loop through the cities, compare distances, overwrite distances if shorter one is found
				current_distance = cityMatrix[currentCity['ID']][citiesB[j]['ID']]
				if current_distance == -1:
					current_distance = cartesianDist(currentCity, citiesB[j])
					cityMatrix[currentCity['ID']][citiesB[j]['ID']] = current_distance            #city A to B
					current_distance = cartesianDist(citiesB[j], currentCity)
					cityMatrix[citiesB[j]['ID']][currentCity['ID']] = current_distance            #city B to A (should be same as A to B)
				if current_distance < current_min_dist:                                               #update the current minimum distance and current minimum city
					current_min_dist = current_distance
					current_min_city = citiesB[j]
			tour_order.append(current_min_city['ID'])                                                     #update the tour order
			citiesB.remove(current_min_city)
			tour_distance += current_min_dist                                                             #update the tour distance

		city_u = citiesA[tour_order[0]]['ID']                                                                 #assign u and v cities
		city_v = citiesA[tour_order[len(tour_order) - 1]]['ID']
		current_distance = cityMatrix[city_u][city_v]                                                         #get the current distance between them
		if current_distance == -1:                                                                            #update the distance if uncalculated
			current_distance = cartesianDist(citiesA[tour_order[0]], citiesA[tour_order[len(tour_order) - 1]])
			cityMatrix[city_u][city_v] = current_distance
			current_distance = cartesianDist(citiesA[tour_order[len(tour_order) - 1]], citiesA[tour_order[0]])
			adjMatrix[city_v][city_u] = current_distance
			
		tour_distance += current_distance                                                                     #update new tour distance
		if tour_distance < tour_min_dist:                                                                     #update new minimum tour distance
			#print(str(time.time()) + " loop#" + str(i) + " tour_d: " + str(tour_distance))                  #for determining best tour under a time constraint
			tour_min_dist = tour_distance
			tour_min_order = [x for x in tour_order]

			outputFile = open(filePath + '.tour', 'w')                                                    #open the output file for writing, adding .tour to end of file
			outputFile.write(str(tour_min_dist) + '\n')                                                   #write the minimum tour distance
			cityIter = iter(tour_min_order)
			for everyCity in cityIter:
				outputFile.write(str(everyCity) + '\n')                                               #write the minimum tour route
			outputFile.close()                                                                            #close the output file
	endTime = time.time()
	runTime = endTime - startTime
	print("Elapsed RunTime: " + str(runTime))

if __name__ == "__main__":                                                                                            #run main()
	main()
