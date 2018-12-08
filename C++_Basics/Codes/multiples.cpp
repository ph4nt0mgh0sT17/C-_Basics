/**********************
*  Using variables   *
**********************/


#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

	// constant variables
	const int from = 1;
	const int to = 10;
	int num;

	cout << "Type a number: ";
	cin >> num;

	int factor = from;

	// normal while cycle
	while (factor <= to)
	{
		int product = num * factor;

		//setw() means set window -> spaces between values
		cout << setw(4) << product;

		// factor++ = factor + 1
		factor++;
	}

	return 0;
}