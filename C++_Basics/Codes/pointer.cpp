/*******************************************************************
 *     Pointers and how we should use them - small example         *
 *******************************************************************/

#include <iostream>

using namespace std;

int main()
{
	// i is variable saved in memory, whereas *pi is pointer to this variable
	// so *pi doesn't have any variable he only points to the variable
	int i, *pi;

	pi = &i; // this is how we point to the variable

	*pi = 123; // and we assign number to this address

	cout << *pi << endl; // here we can see number 123
	cout << i << endl; // and here too


	system("pause");
	return 0;
}