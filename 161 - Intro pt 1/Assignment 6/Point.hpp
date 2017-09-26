/*****
 * Author: Riley Brandau
 * Date: 2/9/16
 * Description: This is the header file for a class called Point. It declares the variables and method prototypes that the class uses
*****/

#ifndef POINT_HPP
#define POINT_HPP

class Point
{
private://declaring private method variables for Point
	double coordX;
	double coordY;
public:// declaring public methods that use the private variables
	void setXCoord(double coord);
	void setYCoord(double coord);
	double getXCoord()const;
	double getYCoord()const;
	Point();
	Point(double x, double y);
	double distanceTo(const Point&); //constant method
};
#endif

