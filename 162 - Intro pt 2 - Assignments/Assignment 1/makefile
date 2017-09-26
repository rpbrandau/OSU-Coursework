#Author: Riley Brandau
#Date: 6/27/16
#Description: makefile for assignment1

CXX = g++
CXXFLAGS = -g -Wall

all: main

main: assignment1.o list.o item.o
	${CXX} ${CXXFLAGS} list.o item.o assignment1.o -o main

assignment1.o: assignment1.cpp
	${CXX} ${CXXFLAGS} -c assignment1.cpp
	
list.o: list.cpp list.hpp
	${CXX} ${CXXFLAGS} -c list.cpp

item.o: item.cpp item.hpp
	${CXX} ${CXXFLAGS} -c item.cpp	

clean:
	$(RM) main *.o *~

	

	
