/**************************************
*   First use of while cycle          *
*   Random generator for dice rolls   *
***************************************/

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
	static int count, total;
	const int TOTAL = 10;

	cout << "I'm rolling the dice until I don't get six " << TOTAL << " times!" << endl;

	// unsigned because I don't want to have negative values
	// need to assign some 'seed' to srand function to generate pseudorandom number
	srand((unsigned)time(NULL));

	while (total < TOTAL)
	{
		// counts how much this while will cycle until it rolls 6
		count++;

		// If random generated number from 0 - 6 equals 6
		if ((rand() % 6 + 1) == 6)
		{
			total++;
		}
	}

	cout << "That's it! There were " << count << " rolls." << endl;

	system("pause");

	return 0;
}