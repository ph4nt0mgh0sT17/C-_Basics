/************************************
*   Using and creating functions    *
*************************************/

#include <iostream>

using namespace std;

// will commenty tomorrow once I understand it...
void cannot_change_byValue(int fa, int fb)
{
	int help_d = fa;
	fa = fb;
	fb = help_d;

}

void exchange_pointer(int *fa, int *fb)
{
	int help_d = *fa;
	*fa = *fb;
	*fb = help_d;
}

void exchange_address(int &fa, int &fb)
{
	int help_d = fa;
	fa = fb;
	fb = help_d;
}

int main()
{
	int x = 123, y = -456;
	cout << "First status" << endl;
	cout << "x: " << x << "; y: " << y << endl;

	cannot_change_byValue(x, y);
	cout << "Function: cannot_change_byValue:" << endl;
	cout << "x: " << x << "; y: " << y << endl;

	exchange_pointer(&x, &y);
	cout << "Function: exchange_pointer:" << endl;
	cout << "x: " << x << "; y: " << y << endl;

	exchange_address(x, y);
	cout << "Function: exchange_address:" << endl;
	cout << "x: " << x << "; y: " << y << endl;

	system("pause");

	return 0;
}