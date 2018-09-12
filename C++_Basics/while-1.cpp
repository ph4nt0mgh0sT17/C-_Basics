#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
	static int count, total;
	const int TOTAL = 10;

	cout << "I'm rolling the dice until I don't get six " << TOTAL << " times!" << endl;

	srand((unsigned)time(NULL));

	while (total < TOTAL)
	{
		count++;
		if ((rand() % 6 + 1) == 6)
		{
			total++ ;
		}
	}

	cout << "That's it! There were " << count << " rolls." << endl;

	system("pause");

	return 0;
}