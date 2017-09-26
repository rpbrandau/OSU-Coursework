#Author: Riley Brandau
#Date: 7/10/16
#Description: makefile for labC

CXX = g++
CXXFLAGS = -g -Wall

all: prog

prog: labC.o
	${CXX} ${CXXFLAGS} labC.o -o prog

labC.o: labC.cpp
	${CXX} ${CXXFLAGS} -c labC.cpp
	

clean:
	$(RM) prog *.o *~

	

	
