/*****
 * Author: Riley Brandau
 * Date: 2/9/16
 * Description: This is the implementation file for a class called LineSegment. It defines the methods and constructors the class uses.
*****/

#include "LineSegment.hpp" //needed for LineSegment prototypes

LineSegment::LineSegment(Point a, Point b)//assigns the end variables Point values
{
	setEnd1(a);
	setEnd2(b);
}

void LineSegment::setEnd1(Point a)
{
	end1 = a;
}

void LineSegment::setEnd2(Point b)
{
	end2 = b;
}

Point LineSegment::getEnd1()
{
	return end1;
}

Point LineSegment::getEnd2()
{
	return end2;
}

double LineSegment::length()//calculates the length between two points
{
	Point p1 = getEnd1();
	Point p2 = getEnd2();
	return p1.distanceTo(p2);
}

double LineSegment::slope()//calculates the slope between two points
{
	double x1 = end1.getXCoord();
	double x2 = end2.getXCoord();
	double y1 = end1.getYCoord();
	double y2 = end2.getYCoord();
	return ((y2-y1)/(x2-x1));
}

