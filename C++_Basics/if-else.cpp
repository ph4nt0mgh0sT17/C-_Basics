/*
	If else example
*/

#include <iostream>

using namespace std;

int main()
{
	// Just using if branches, there is nothing to explain at all
	// Just trying to use pointer as much as I can to learn its purpose
	double *a = new double, *b = new double;
	cout << "Type two double numbers: ";
	cin >> *a >> *b;

	if (*b == 0.0)
		cout << "\aCannot divide by Zero!!!"; // /a means alarm
	else
	{
		double *fraction = new double(*a / *b);
		

		delete a; delete b;

		cout << &fraction << endl; //Reference to reference of value
		cout << "Their fraction is: " << fraction << endl; // Reference to value
	}

	system("pause");

	return 0;
}