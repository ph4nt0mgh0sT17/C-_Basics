/***********************************************
*   Using characters in if, else if branches   *   
************************************************/

#include <iostream>

using namespace std;

int main()
{
	char *_char = new char;
	cout << "Type a char: ";
	cin >> *_char;

	cout << endl << "You typed ";

	if ((*_char >= 'a') && (*_char <= 'z'))
		cout << "small char.";

	else if ((*_char >= 'A') && (*_char <= 'Z'))
		cout << "capital char.";

	else if ((*_char >= '0') && (*_char <= '9'))
		cout << "a number.";

	else
		cout << "You did't typed a char!";

	delete _char;

	cout << endl;

	system("pause");

	return 0;
		
}