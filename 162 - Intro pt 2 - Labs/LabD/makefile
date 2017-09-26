#Author: Riley Brandau
#Date: 7/17/16
#Description: makefile for cs162 Lab D

CXX = g++
CXXFLAGS = -g -Wall

all: prog

prog: labD.o toUpper.o orderedOutput.o encryption.o copy.o transformer.o
	${CXX} ${CXXFLAGS} labD.o toUpper.o orderedOutput.o encryption.o copy.o transformer.o -o prog

labD.o: labD.cpp
	${CXX} ${CXXFLAGS} -c labD.cpp
	
toUpper.o: toUpper.cpp toUpper.hpp
	${CXX} ${CXXFLAGS} -c toUpper.cpp
	
orderedOutput.o: orderedOutput.cpp orderedOutput.hpp
	${CXX} ${CXXFLAGS} -c orderedOutput.cpp
	
encryption.o: encryption.cpp encryption.hpp
	${CXX} ${CXXFLAGS} -c encryption.cpp
	
copy.o: copy.cpp copy.hpp
	${CXX} ${CXXFLAGS} -c copy.cpp
	
transformer.o: transformer.cpp transformer.hpp
	${CXX} ${CXXFLAGS} -c transformer.cpp
	
clean:
	$(RM) prog *.o *~

	

	
