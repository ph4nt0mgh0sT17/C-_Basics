#include <iostream>
#include <string>

using namespace std;

class polar
{
	double r, fi;

public:
	polar(double a, double b)
	{
		r = a; fi = b;
	};

	double get_r(void) { return r; }
	double get_fi(void) { return fi; }
};

void print(int num)
{
	cout << "number: " << num << endl;
}

void print(double num)
{
	cout << "number: " << num << endl;
}

void print(string s)
{
	cout << "string: " << s << endl;
}

void print(polar p)
{
	cout << "r: " << p.get_r() << endl
	<< "fi: " << p.get_fi() << endl;
}

int main()
{
	int i = 29;
	double x = 2003.7;
	string s = "part";
	polar y(65.43, 7);

	print(i);
	print(x);
	print(s);
	print(y);
	
	system("pause");

	return 0;
}

