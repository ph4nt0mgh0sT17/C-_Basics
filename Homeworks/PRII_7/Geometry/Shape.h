#pragma once
class Shape
{
protected:
	double width, height;
public:
	Shape(double width);
	Shape(double width, double height);

	double GetPerimeter();
	double GetArea();
};

