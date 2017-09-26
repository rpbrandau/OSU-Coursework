#Author: Riley Brandau
#Date: 7/12/16
#Description: makefile for labAb

CXX = g++
CXXFLAGS = -g -Wall

all: labAb

labAb: labAb.o summation.o average.o
	${CXX} ${CXXFLAGS} labAb.o summation.o average.o -o labAb

labAb.o: labAb.cpp
	${CXX} ${CXXFLAGS} -c labAb.cpp
	
summation.o: summation.cpp summation.hpp
	${CXX} ${CXXFLAGS} -c summation.cpp
	
average.o: average.cpp average.hpp
	${CXX} ${CXXFLAGS} -c average.cpp

clean:
	$(RM) labAb *.o *~

	

	
