/*****
 * Author: Riley Brandau
 * Date: 2/9/16
 * Description: This is the implementation file for a class called Point. It defines the methods and constructors the class uses.
*****/

#include "Point.hpp"
#include <cmath> //for sqrt() and pow()

void Point::setXCoord(double x)//methods for setting x & y coordinates
{
	coordX = x;
}

void Point::setYCoord(double y)
{
	coordY = y;
}

Point::Point() //default constructor to set coordinates to 0
{
	setXCoord(0);
	setYCoord(0);
}

Point::Point(double x, double y)//constructor to set coordinates to x & y
{
	setXCoord(x);
	setYCoord(y);
}

double Point::getXCoord()const//method for returning x coordinate
{
	return coordX;
}

double Point::getYCoord()const//method for returning y coordinate
{
	return coordY;
}

double Point::distanceTo(const Point &point) //constant method for returning distance between two points
{                                           //formula: square root of ((x2-x1)^2)+(y2-y1)^2)
	double part1;
	double part2;

	part1 = coordX - point.getXCoord();
	part2 = coordY - point.getYCoord();

	return sqrt(pow(part1,2) + pow(part2,2));
}

