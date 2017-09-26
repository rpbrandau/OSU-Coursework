//this program uses the Rectangle Class

#include <iostream>
#include "Box.hpp"
using namespace std;

int main()
{
	Box crate(10.0, 10.0, 10.0);
	double crateLength,
	       crateWidth,
	       crateHeight;
/*
	cout << "This program will calculate the volume and surface area of a box.\n";
	cout << "What is the length, width, and height? ";
	cin >> crateLength >> crateWidth >> crateHeight;


	//call member functions to set box dimensions
	crate.setLength(crateLength);
	crate.setWidth(crateWidth);
	crate.setHeight(crateHeight);
*/	
	//call member functions to display values
	cout << "\nHere is the box's data:\n";
	cout << "Length: " << crate.getLength() << endl;
	cout << "Width: " << crate.getWidth() << endl;
	cout << "Height: " << crate.getHeight() << endl;
	cout << "Volume: " << crate.getVolume() << endl;
	cout << "Surface Area: " << crate.getSurfaceArea() << endl;
	
	//testing default construtor
	Box crate2;
	cout << "\nHere is the default box's data:\n";
	cout << "Length: " << crate2.getLength() << endl;
	cout << "Width: " << crate2.getWidth() << endl;
	cout << "Height: " << crate2.getHeight() << endl;
	cout << "Volume: " << crate2.getVolume() << endl;
	cout << "Surface Area: " << crate2.getSurfaceArea() << endl;

	return 0;
}

