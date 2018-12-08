/******************************************************
*   Using exceptions for avoiding application crash   *
*******************************************************/

#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

using namespace std;

int main()
{
	string typed = "";
	cout << "Type long string: ";
	getline(cin, typed, '\n');

	cout << "String is long for " << typed.size() << " chars." << endl;

	try
	{
		for (int i = 0; i < 10; i++)
		{
			cout << typed.at(i) << " ";
		}
	}
	catch (out_of_range e)
	{
		cout << "Caught exception!" << endl;
		cout << "Its description: " << e.what() << endl;
	}

	system("pause");
	return 0;
}