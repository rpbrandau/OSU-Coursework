#Author: Riley Brandau
#Date: 6/30/16
#Description: makefile for labB

CXX = g++
CXXFLAGS = -g -Wall

all: prog

prog: labB.o dice.o loadedDice.o
	${CXX} ${CXXFLAGS} loadedDice.o dice.o labB.o -o prog

labB.o: labB.cpp
	${CXX} ${CXXFLAGS} -c labB.cpp
	
dice.o: dice.cpp dice.hpp
	${CXX} ${CXXFLAGS} -c dice.cpp

loadedDice.o: loadedDice.cpp loadedDice.hpp
	${CXX} ${CXXFLAGS} -c loadedDice.cpp	

clean:
	$(RM) prog diceStats.txt *.o *~

	

	
