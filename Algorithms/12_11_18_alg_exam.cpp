#include <iostream>
#include <string>
#include <sstream>

using namespace std;


void space();
long factorial(int n);


int main(void)
{
	cout << "\t\tAlgorithms - 11/12/18" << endl;
	cout << "\t\tAuthor: David Miko" << endl;
	space();
	cout << "Type a factorial: ";

	string n;

	getline(cin, n, '\n');

	for (int i = 0; i < n.length(); i++)
	{
		int index = (int)n.at(i);

		if ((index < 48 || index > 57))
		{
			if (index != 32)
			{
				cout << "Error." << endl;
				system("pause");
				return (-1);
			}
		}
	}

	stringstream ss(n);

	int num;
	ss >> num;

	

	

	if (num > 30)
	{
		cout << "Factorial is too high." << endl;
		return (-1);
	}

	cout << "Factorial of " << num << " is: " << factorial(num) << endl;
	system("pause");
	return (0);
}

long factorial(int n)
{
	if (n == 0)
	{
		return 1;
	}

	long num = 1;
	for (int i = 1; i <= n; i++)
	{
		num *= i;
	}


	return (num);
}

void space()
{
	cout << "===========================================================" << endl;
}
