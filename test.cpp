#include "Vektor.h"
#include <iostream>

struct Point
{
	int x, y;
};


int main()
{
	Point firstpoint = { 5,6 };
	Vektor<Point> points;

	points.Push_back(firstpoint);
	points.Push_back(firstpoint);
	points.Push_back(firstpoint);
	points.Push_back(firstpoint);
	points.Push_back(firstpoint);
	points.At(4);
	
	std::cout << "ok" << std::endl;
}