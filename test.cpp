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

	if (points.Is_Empty())
		std::cout << "Empty" << std::endl;

	points.Push_back(firstpoint);
	points.Push_back(firstpoint);
	points.Push_back(firstpoint);
	points.Push_back(firstpoint);
	points.Push_back(firstpoint);
	points.Push_back(firstpoint);
	points.Push_back(firstpoint);
	points.Push_back(firstpoint);
	points.Push_back(firstpoint);
	points.Push_back(firstpoint);
	points.Push_back(firstpoint);
	points.Push_back(firstpoint);
	points.Push_back(firstpoint);
	points.Push_back(firstpoint);

	if (points.Is_Empty())
		std::cout << "Empty" << std::endl;
	else
		std::cout << "Not empty" << std::endl;

}