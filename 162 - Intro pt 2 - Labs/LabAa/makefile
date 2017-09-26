#Author: Riley Brandau
#Date: 6/21/16
#Description: makefile for LabAa / LabAaEx

CXX = g++
CXXFLAGS = -g -Wall

all: avgMain avgMainEx sumMain sumMainEx

avgMain: avgMain.o average.o
	${CXX} ${CXXFLAGS} avgMain.o average.o -o avgMain

avgMainEx: avgMainEx.o average.o
	${CXX} ${CXXFLAGS} avgMainEx.o average.o -o avgMainEx

sumMain: sumMain.o summation.o
	${CXX} ${CXXFLAGS} sumMain.o summation.o -o sumMain

sumMainEx: sumMainEx.o summation.o
	${CXX} ${CXXFLAGS} sumMainEx.o summation.o -o sumMainEx

avgMain.o: avgMain.cpp
	${CXX} ${CXXFLAGS} -c avgMain.cpp

avgMainEx.o: avgMainEx.cpp
	${CXX} ${CXXFLAGS} -c avgMainEx.cpp
	
sumMain.o: sumMain.cpp
	${CXX} ${CXXFLAGS} -c sumMain.cpp
	
sumMainEx.o: sumMainEx.cpp
	${CXX} ${CXXFLAGS} -c sumMainEx.cpp
	
average.o: average.cpp average.hpp
	${CXX} ${CXXFLAGS} -c average.cpp

summation.o: summation.cpp summation.hpp
	${CXX} ${CXXFLAGS} -c summation.cpp	

clean:
	$(RM) avgMain avgMainEx sumMain sumMainEx *.o *~

	

	
