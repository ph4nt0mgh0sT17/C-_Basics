#pragma once
#include "Shape.h"

class Square : public Shape
{

public:
	Square(int width);

	int GetPerimeter();
	int GetArea();

};

