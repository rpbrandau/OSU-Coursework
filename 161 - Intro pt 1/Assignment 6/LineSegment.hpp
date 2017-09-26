/*****
 * Author: Riley Brandau
 * Date: 2/9/16
 * Description: This is the header file for a class called LineSegment. It declares the variables and methods that will be used by the class.
*****/

#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP
#include "Point.hpp" //needed since it uses Point member functions

class LineSegment
{
private:
	Point end1;
	Point end2;
public:
	void setEnd1(Point point1);
	void setEnd2(Point point2);
	Point getEnd1(); //point class functions
	Point getEnd2();
	LineSegment(Point a, Point b);
	double length();
	double slope();
};
#endif
