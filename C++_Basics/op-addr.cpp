/***************
*  Addressing  *
****************/

#include <iostream>

using namespace std;

int main()
{
	int i = 123, *pi;

	pi = &i;

	cout << "Variable i = " << i << " is in address: " << pi << endl;

	system("pause");

	return 0;
}