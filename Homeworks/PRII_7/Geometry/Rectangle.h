#pragma once
#include "Shape.h"
#include <string>
class Rectangle : public Shape
{
public:
	Rectangle(double width, double height);

	double GetPerimeter();
	double GetArea();

	std::string GetInformation();
};

