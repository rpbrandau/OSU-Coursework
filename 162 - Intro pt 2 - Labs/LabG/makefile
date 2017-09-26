#Author: Riley Brandau
#Date: 8/7/16
#Description: makefile for cs162 LabG

CXX = g++
CXXFLAGS = -g -Wall

all: prog

prog: labG.o linearSearch.o bubbleSort.o binarySearch.o
	${CXX} ${CXXFLAGS} labG.o linearSearch.o bubbleSort.o binarySearch.o  -o prog

labG.o: labG.cpp
	${CXX} ${CXXFLAGS} -c labG.cpp
	
linearSearch.o: linearSearch.cpp linearSearch.hpp
	${CXX} ${CXXFLAGS} -c linearSearch.cpp
	
bubbleSort.o: bubbleSort.cpp bubbleSort.hpp
	${CXX} ${CXXFLAGS} -c bubbleSort.cpp
	
binarySearch.o: binarySearch.cpp binarySearch.hpp
	${CXX} ${CXXFLAGS} -c binarySearch.cpp
	
clean:
	$(RM) prog *.o *~

	

	
