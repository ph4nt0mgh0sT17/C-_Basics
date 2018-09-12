/*
	Application for listing all chars from ASCII table
*/

#include <iostream>

using namespace std;

int main()
{
	int _char = 32;

	cout << endl;

	do // do-while cycle, which is used mostly because it can be used anytime
	{
		cout << (char)_char++;
		if (_char % 16 == 0)
		{
			cout << endl;
		}
	} while (_char < 128);


	system("pause");
	return 0;
}