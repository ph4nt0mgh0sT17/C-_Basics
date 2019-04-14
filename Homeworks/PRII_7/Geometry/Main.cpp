#include <iostream>
#include <string>

#include "Rectangle.h"
#include "Square.h"

int main(void)
{
	
	Rectangle* rectangleNew = new Rectangle(10, 10);
	Square* squareNew = new Square(4);

	std::cout<< rectangleNew->GetInformation() << std::endl << std::endl;
	std::cout << squareNew->GetInformation() << std::endl << std::endl;

	getchar();

	return (0);
}
