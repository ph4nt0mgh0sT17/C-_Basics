/******************************
*   Using condition operator  *
*******************************/

#include <iostream>

using namespace std;

int main()
{
	int i, abs_i;

	cout << endl << "Type integer: ";
	cin >> i;

	abs_i = (i < 0) ? -i : i;

	cout << "abs(\"<< i <<\") = " << abs_i << endl;

	system("pause");

	return 0;
}