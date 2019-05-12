#pragma once
class Shape
{
protected:
	int width;
	int height;
public:
	Shape(int width);
	Shape(int width, int height);

	virtual int GetPerimeter() = 0;
	virtual int GetArea() = 0;
};

