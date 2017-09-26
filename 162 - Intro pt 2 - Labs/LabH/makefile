#Author: Riley Brandau
#Date: 8/8/16
#Description: makefile for cs162 LabFb

CXX = g++
CXXFLAGS = -g -Wall

all: prog_R prog_I

prog_R: labH.o 
	${CXX} ${CXXFLAGS}  labH.o -o prog_R

prog_I: LabH_iMergesort.o
	${CXX} ${CXXFLAGS}  LabH_iMergesort.o -o prog_I
	
LabH_iMergesort.o: LabH_iMergesort.cpp
	${CXX} ${CXXFLAGS} -c LabH_iMergesort.cpp
	
labH.o: labH.cpp
	${CXX} ${CXXFLAGS} -c labH.cpp

clean:
	$(RM) prog_R prog_I *.o *~

	

	
