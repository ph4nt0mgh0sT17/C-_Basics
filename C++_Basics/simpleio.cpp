/**********************
*  Using variables   *
**********************/


#include <iostream>

using namespace std;

int main()
{

	// Console output
	cout << "Input two numbers, please:" << endl;

	//two variables
	int x, y;

	//Input to 2 variables from user
	cin >> x >> y;

	// Result of adding two numbers
	cout << x << " + " << y << " = " << x + y << endl;


	cout << "Input a number:" << endl;

	// New variable
	double num;

	cin >> num;

	// We can also use a variable for storing data
	double numX = num * x;


	cout << x << " * " << num << " = " << numX << endl;

	return 0;
}