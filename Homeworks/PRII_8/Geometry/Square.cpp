#include "Square.h"



Square::Square(int width) : Shape(width)
{
}

int Square::GetPerimeter()
{
	return (4 * this->width);
}

int Square::GetArea()
{
	return (this->width * this->height);
}


