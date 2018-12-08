/*
	Application for getting all ASCII chars
*/

#include <iostream>

using namespace std;

int main()
{
	cout << endl;

	for (int _char = 32; _char < 128; _char++) // typical for cycle
	{
		if (_char % 16 == 0) // just for visual comfort
		{
			cout << endl;
		}

		cout << (char)_char;
	}

	cout << endl;

	system("pause");
	return 0;
}