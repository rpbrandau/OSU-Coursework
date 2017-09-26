/*****
 * Author: Riley Brandau
 * Date: 2/2/16
 * Description: This is the implementation file for the class "Box"
 * It defines all of the methods/functions that the Box class can use.
*****/

#include "Box.hpp"

//implementation code for all of the variable sets
void Box::setLength(double len)
{	
	length = len;
}

void Box::setWidth(double w)
{
	width = w;
}

void Box::setHeight(double h)
{
	height = h;
}


//implementation code for all of the variable gets
double Box::getLength()
{
	return length;
}

double Box::getWidth()
{
	return width;
}

double Box::getHeight()
{
	return height;
}


//implementation code for all of the variable calculations
double Box::getVolume()
{
	return length * width * height;
}

double Box::getSurfaceArea()
{
	return ((2.0 * length * width) + (2.0 * width * height) + (2.0 * length * height));
}

//Default box constructor
Box::Box()
{
	length = 1.0;
	width = 1.0;
	height = 1.0;
}

//three parameter box constructor
Box::Box(double l, double w, double h)
{
	length = l;
	width = w;
	height = h;
}
