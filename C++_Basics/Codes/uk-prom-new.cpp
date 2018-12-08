/*********************************
 *	Pointer and getting address  *
 *********************************/

#include <iostream>

using namespace std;

int main()
{
	// creating variable x with value, and pointer *udbl
	double x = -12.3, *udbl;

	//assigning address to udbl
	udbl = &x;
	

	//Writing out to proof the pointer points to variable x
	cout << "x = " << x << "; &x = " << &x << endl;
	cout << "*udbl = " << *udbl << "; udbl = " << udbl << endl;
	cout << "udbl = " << udbl << "; &udbl = " << &udbl << endl << endl;

	// Changing value in pointer
	cout << "Type a number: ";
	cin >> *udbl;


	// Proof that changin value in pointer, changes value in the variable itself
	cout << "x = " << x << "; &x = " << &x << endl;
	cout << "*udbl = " << *udbl << "; udbl = " << udbl << endl;
	cout << "udbl = " << udbl << "; &udbl = " << &udbl << endl << endl;;


	// dynamic allocation variable to pointer, so pointer no longer points to variable x, but to dynamic variable
	udbl = new double;

	// setting value to pointer
	cout << "Type a double: ";
	cin >> *udbl;
 

	//showing that value in pointer is different than in variable x
	cout << "x = " << x << "; &x = " << &x << endl;
	cout << "*udbl = " << *udbl << "; udbl = " << udbl << endl;
	cout << "udbl = " << udbl << "; &udbl = " << &udbl << endl;
	

	system("pause");
	return 0;
}