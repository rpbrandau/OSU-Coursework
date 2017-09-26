#Author: Riley Brandau
#Date: 8/6/16
#Description: makefile for cs162 Final Assignment

CXX = g++
CXXFLAGS = -g -Wall

all: prog

prog: finalAssignment.o bakery.o butchers.o cannedGoods.o dairy.o entrance.o frozenFoods.o home.o item.o outside.o player.o produce.o space.o
	${CXX} ${CXXFLAGS} finalAssignment.o bakery.o butchers.o cannedGoods.o dairy.o entrance.o frozenFoods.o home.o item.o outside.o player.o produce.o space.o  -o prog

finalAssignment.o: finalAssignment.cpp
	${CXX} ${CXXFLAGS} -c finalAssignment.cpp
	
bakery.o: bakery.cpp bakery.hpp
	${CXX} ${CXXFLAGS} -c bakery.cpp
	
butchers.o: butchers.cpp butchers.hpp
	${CXX} ${CXXFLAGS} -c butchers.cpp
	
cannedGoods.o: cannedGoods.cpp cannedGoods.hpp
	${CXX} ${CXXFLAGS} -c cannedGoods.cpp

dairy.o: dairy.cpp dairy.hpp
	${CXX} ${CXXFLAGS} -c dairy.cpp

entrance.o: entrance.cpp entrance.hpp
	${CXX} ${CXXFLAGS} -c entrance.cpp

frozenFoods.o: frozenFoods.cpp frozenFoods.hpp
	${CXX} ${CXXFLAGS} -c frozenFoods.cpp

home.o: home.cpp home.hpp
	${CXX} ${CXXFLAGS} -c home.cpp

item.o: item.cpp item.hpp
	${CXX} ${CXXFLAGS} -c item.cpp

outside.o: outside.cpp outside.hpp
	${CXX} ${CXXFLAGS} -c outside.cpp

player.o: player.cpp player.hpp
	${CXX} ${CXXFLAGS} -c player.cpp

produce.o: produce.cpp produce.hpp
	${CXX} ${CXXFLAGS} -c produce.cpp

space.o: space.cpp space.hpp
	${CXX} ${CXXFLAGS} -c space.cpp
	
clean:
	$(RM) prog *.o *~

	

	
