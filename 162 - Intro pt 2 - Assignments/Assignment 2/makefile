#Author: Riley Brandau
#Date: 7/10/16
#Description: makefile for assignment 2

CXX = g++
CXXFLAGS = -g -Wall

all: prog

prog: assignment2.o critter.o ant.o doodlebug.o
	${CXX} ${CXXFLAGS} ant.o assignment2.o critter.o doodlebug.o -o prog

critter.o: critter.cpp critter.hpp
	${CXX} ${CXXFLAGS} -c critter.cpp
	
ant.o: ant.cpp ant.hpp
	${CXX} ${CXXFLAGS} -c ant.cpp
	
doodlebug.o: doodlebug.cpp doodlebug.hpp
	${CXX} ${CXXFLAGS} -c doodlebug.cpp

assignment2.o: assignment2.cpp
	${CXX} ${CXXFLAGS} -c assignment2.cpp

clean:
	$(RM) prog *.o *~

	

	
