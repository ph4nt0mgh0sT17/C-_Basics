#pragma once

#include "Shape.h"

#include <string>
class Square : public Shape
{
public:
	Square(double width);

	double GetPerimeter();
	double GetArea();

	std::string GetInformation();
};

