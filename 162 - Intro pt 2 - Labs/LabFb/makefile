#Author: Riley Brandau
#Date: 8/8/16
#Description: makefile for cs162 LabFb

CXX = g++
CXXFLAGS = -g -Wall

all: prog

prog: labFb.o postfixCalc.o stack.o
	${CXX} ${CXXFLAGS}  labFb.o postfixCalc.o stack.o -o prog

labFb.o: labFb.cpp
	${CXX} ${CXXFLAGS} -c labFb.cpp
	
stack.o: stack.cpp stack.hpp
	${CXX} ${CXXFLAGS} -c stack.cpp
	
postfixCalc.o: postfixCalc.cpp postfixCalc.hpp
	${CXX} ${CXXFLAGS} -c postfixCalc.cpp

clean:
	$(RM) prog *.o *~

	

	
