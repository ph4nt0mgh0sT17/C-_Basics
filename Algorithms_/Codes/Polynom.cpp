#include <iostream>

using namespace std;

double CalculatePolynom(double *koeficient, int n, double alpha);

int main(void)
{
	const int N = 6;
	const double ALPHA = 6;
	const int polynomLevel = N - 1;
	double *pPolynom = new double[N] { 4, 5, -1, 7, 0, 3};

	if (polynomLevel + 1 != N)
	{
		cout << "Wrong polynom." << endl;
		system("pause");
		return -1;
	}

	cout << "P(" << ALPHA << ") = " << CalculatePolynom(pPolynom, polynomLevel, ALPHA);

	system("pause");
	return 0;
}

double CalculatePolynom(double *koeficient, int n, double alpha)
{
	int i = n + 1;
	double result = 0;

	for (i >= 0; i--;)
	{

		result += koeficient[i] * (pow(alpha, i));
	}


	return result;
}
