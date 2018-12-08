/***********************************************************************
 *    Using addresses to values and deleting this values - quick way   * 
 ***********************************************************************/

#include <iostream>
using namespace std;

int main()
{
	
	// dynamic allocation variable to address - int i = 3; int *ptr = &i; (same)
	int *ptr = new int(3); // 3

	//adding value
	*ptr += 7; // 10
	cout << "*ptr = " << *ptr << endl; // *ptr = 10

	//remove value from address, cannot remove address (*ptr)
	delete ptr;

	int count;
	cout << "How much elements-array do you want to create?: ";
	cin >> count;
	
	// Same way as above
	double *_array = new double[count];
	int i = 0;
	
	// Simple assigning values to array
	while (i < count)
	{
		_array[i] = i + (double)i / 100;
		cout << _array[i] << endl;
		i++;
	}

	// delete array
	delete[] _array;

	system("pause");

	return 0;
}