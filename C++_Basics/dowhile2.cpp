#include <iostream>
#include <iomanip>

using namespace std;

const long double error = 1.0e-15L;

int main()
{
	long double e = 1.0L, epsilon = 1.0L; // double with longer floating point
	unsigned long n = 0L;

	cout << endl;

	do
	{
		epsilon /= ++n;
		e += epsilon;
	} while (epsilon > error);

	cout << "e = " << setprecision(5) << e << " count of iteration: " << n << endl; // setprecision means count of floating point showed in console

	system("pause");

	return 0;
}