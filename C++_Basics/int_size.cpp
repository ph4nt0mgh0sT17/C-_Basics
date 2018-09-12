/***********************************************
*   How to find out how much bits translation  *
************************************************/

#include <iostream>

using namespace std;

int main()
{
	unsigned int ui = ~0;
	int i = 1;

	// >>= is bit move to right so ui in this phase is 1 because ~0 is (zero factorial) = 1
	// and unsigned int is 32 bit number so it adds to right as long as it can before it overflow
	// trick for finding out if its 32bit
	while (ui >>= 1)
	{
		i++;
	}

	cout << i;

	system("pause");

	return 0;


}