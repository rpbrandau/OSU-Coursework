

#include "LineSegment.hpp"
#include <iostream>

using namespace std;

int main()
{
	double x1; 
	double x2;
	double y1;
	double y2;
	
	cout << "enter x1 y1" << endl;
	cin >> x1 >> y1;
	cout << "enter x2 y2" << endl;
	cin >> x2 >> y2;
	
	Point p1(x1, y1);
	Point p2(x2, y2);
	double dist = p1.distanceTo(p2);
	cout << "P1(" << x1 << "," << y1 << ")" << endl;
	cout << "P2(" << x2 << "," << y2 << ")" << endl;
	cout << "Distance: " << dist << endl;
	
	LineSegment line(p1, p2);
	double length = line.length();
	double slope = line.slope();
	cout << "Length: " << length << endl;
	cout << "Slope: " << slope << endl;

return 0;
}
