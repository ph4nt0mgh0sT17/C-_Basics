/*************************************************************
 *   Fundamental arithmetic operations and assigning         * 
 *************************************************************/

#include <iostream>

using namespace std;

int main()
{
	int i, j;
	double r, x;

	j = i = 5; // assigning to 2 variables in 1 row (not good if you are paid for number of code rows)
	j *= i; // 25

	// We can retype variable j (int) to double
	r = (double) j / 3;
	x = j * 3; // 75
	
	cout << "i = " << i << "; j = " << j << "; r = " << r << "; x = " << x << endl;

	system("pause");

	return 0;
}