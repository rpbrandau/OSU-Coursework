#Author: Riley Brandau
#Date: 7/24/16
#Description: makefile for cs162 labE

CXX = g++
CXXFLAGS = -g -Wall

all: prog

prog: labE.o list.o 
	${CXX} ${CXXFLAGS} labE.o list.o  -o prog

labE.o: labE.cpp
	${CXX} ${CXXFLAGS} -c labE.cpp
	
list.o: list.cpp list.hpp
	${CXX} ${CXXFLAGS} -c list.cpp
	
clean:
	$(RM) prog *.o *~

	

	
