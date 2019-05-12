#include <iostream>

#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"

using namespace std;

void GetInformation(Shape* shape)
{
	cout << "This object has perimeter: " << shape->GetPerimeter() << " cm and area: " << shape->GetArea() << " cm." << endl;
	cout << endl << "------------------------------------------------------------------" << endl << endl;
}

int main()
{
	cout << "AHOJ" << endl;

	Shape** shapes = new Shape * [5];

	shapes[0] = new Rectangle(10, 15);
	shapes[1] = new Square(4);
	shapes[2] = new Rectangle(4, 8);
	shapes[3] = new Square(8);
	shapes[4] = new Rectangle(9, 10);

	for (int i = 0; i < 5; i++)
	{
		GetInformation(shapes[i]);
	}


	getchar();
	return (0);
}
