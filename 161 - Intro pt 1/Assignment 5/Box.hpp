/*****
 * Author: Riley Brandau
 * Date: 2/2/16
 * Description: This is the class specification file for a class called Box.
*****/

#ifndef BOX_HPP
#define BOX_HPP

//class declaration
class Box
{
	private:
//declaring private variables for box
		double length;
		double width;
		double height;
	public:
//declaring box methods
		void setLength(double);
		void setWidth(double);
		void setHeight(double);
		double getLength();
		double getWidth();
		double getHeight();
//methods for calculations
		double getVolume();
		double getSurfaceArea();
//default constructor
		Box();
//three parameter constructor
		Box(double, double, double );
};
//if another BOX_HPP is found, everything between #ifndef and #endif will be skipped
#endif

