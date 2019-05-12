#include "Rectangle.h"


Rectangle::Rectangle(int width, int height) : Shape(width, height)
{
}

int Rectangle::GetPerimeter()
{
	return (2 * (this->width + this->height));
}

int Rectangle::GetArea()
{
	return (this->width * this->height);
}
