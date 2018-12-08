/**********************************************
*   Using switch (multiple if and if else)    *
***********************************************/

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
	string *s = new string;
	
	cout << "Rolling a dice..." << endl;
	srand(time(NULL));
	
	switch (rand() % 6+1)
	{
	case 1: *s = "one";
		break;

	case 2: *s = "two";
		break;

	case 3: *s = "three";
		break;

	case 4: *s = "four";
		break;

	case 5: *s = "five";
		break;

	default: *s = "six";
		break;
	}

	cout << "It's a " << *s << endl;

	delete s;

	system("pause");

	return 0;
}