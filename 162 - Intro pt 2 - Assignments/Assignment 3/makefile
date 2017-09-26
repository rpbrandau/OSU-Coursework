#Author: Riley Brandau
#Date: 7/21/16
#Description: makefile for cs162 Assignment 3

CXX = g++
CXXFLAGS = -g -Wall

all: prog

prog: assignment3.o creature.o medusa.o gollum.o reptilePeople.o blueMen.o harryPotter.o
	${CXX} ${CXXFLAGS} assignment3.o creature.o medusa.o gollum.o reptilePeople.o blueMen.o harryPotter.o -o prog

assignment3.o: assignment3.cpp
	${CXX} ${CXXFLAGS} -c assignment3.cpp
	
creature.o: creature.cpp creature.hpp
	${CXX} ${CXXFLAGS} -c creature.cpp
	
gollum.o: gollum.cpp gollum.hpp
	${CXX} ${CXXFLAGS} -c gollum.cpp
	
reptilePeople.o: reptilePeople.cpp reptilePeople.hpp
	${CXX} ${CXXFLAGS} -c reptilePeople.cpp
	
blueMen.o: blueMen.cpp blueMen.hpp
	${CXX} ${CXXFLAGS} -c blueMen.cpp
	
harryPotter.o: harryPotter.cpp harryPotter.hpp
	${CXX} ${CXXFLAGS} -c harryPotter.cpp
	
medusa.o: medusa.cpp medusa.hpp
	${CXX} ${CXXFLAGS} -c medusa.cpp
	
clean:
	$(RM) prog *.o *~

	

	
