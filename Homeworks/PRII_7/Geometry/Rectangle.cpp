#include "Rectangle.h"


Rectangle::Rectangle(double width, double height) : Shape(width, height)
{
}

double Rectangle::GetPerimeter()
{
	return 2 * (this->width + this->height);
}

double Rectangle::GetArea()
{
	return this->width* this->height;
}

std::string Rectangle::GetInformation()
{
	return "This rectangle has: " + std::to_string(this->width) + " width and " + std::to_string(this->height) + " height; Perimeter: " + std::to_string(this->GetPerimeter()) + "; Area:" + std::to_string(this->GetArea());
} 
