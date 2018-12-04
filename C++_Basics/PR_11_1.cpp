#include <iostream>

using namespace std;

void calculateRobotStep(int *coord);

int main(void)
{
	int steps;

	cin >> steps;

	if (cin.fail() || steps < 1)
	{
		cout << "Nespravny vstup.";
		return -1;
	}


	/*
	 *
	 */
	double *coord_info = new double[6];

	for (int i = 0; i < 6; i++)
	{
		cin >> coord_info[i];

		if (cin.fail())
		{
			cout << "Nespravny vstup.";
			return -1;
		}
	}



#ifndef __PROGTEST__
	system("pause");
#endif

	return 0;
}


/// <summary>Calculate robot's next step according to coord informations</summary>
void calculateRobotStep(int *coord)