#Author: Riley Brandau
#Date: 7/29/16
#Description: makefile for cs162 labFa

CXX = g++
CXXFLAGS = -g -Wall

all: prog

prog: labFa.o stack.o queue.o
	${CXX} ${CXXFLAGS} labFa.o stack.o queue.o  -o prog

labFa.o: labFa.cpp
	${CXX} ${CXXFLAGS} -c labFa.cpp
	
stack.o: stack.cpp stack.hpp node.hpp
	${CXX} ${CXXFLAGS} -c stack.cpp
	
queue.o: queue.cpp queue.hpp node.hpp
	${CXX} ${CXXFLAGS} -c queue.cpp
	
clean:
	$(RM) prog *.o *~

	

	
