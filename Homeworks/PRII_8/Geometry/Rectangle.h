#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(int width, int height);

	int GetPerimeter();
	int GetArea();

};

