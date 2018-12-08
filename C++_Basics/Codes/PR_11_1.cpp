#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

void calculateRobotStep(double *coord);

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

	for (int i = 0; i < steps; i++)
	{
		calculateRobotStep(coord_info);

		cout << fixed << setprecision(2) << "x: " << coord_info[0] << ", y: " << coord_info[1] << ", fi: " << coord_info[2] << endl;
	}



#ifndef __PROGTEST__
	system("pause");
#endif

	return 0;
}


/// <summary>
/// Calculation of next robot step due to his coordinations.
/// coord[6] = {x, y, angle of robot (fi), delta, velocity (v), angle after step (omega)}
/// </summary>
void calculateRobotStep(double *coord)
{
	double x = coord[0] + (coord[4] * coord[3] * cos(coord[2]));
	double y = coord[1] + (coord[4] * coord[3] * sin(coord[2]));
	double fi = coord[2] + (coord[3] * coord[5]);

	if (fi > (2 * M_PI))
	{
		fi = fi - (2 * M_PI);
	}

	else if (fi < 0)
	{
		fi = fi + (2 * M_PI);
	}

	coord[0] = x;
	coord[1] = y;
	coord[2] = fi;
}