#include "Square.h"

Square::Square(double width) : Shape(width)
{
}

double Square::GetPerimeter()
{
	return 4 * this->width;
}

double Square::GetArea()
{
	return this->width * this->height;
}

std::string Square::GetInformation()
{
	return "This rectangle has: " + std::to_string(this->width) + " width and " + std::to_string(this->height) + " height; Perimeter: " + std::to_string(this->GetPerimeter()) + "; Area:" + std::to_string(this->GetArea());
}
