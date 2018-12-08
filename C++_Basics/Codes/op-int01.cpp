/********************************************************************
 *   Integer multiplication, division, remainder after division     *
 *	 There is shown integer overflow                                *
 ********************************************************************/


#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int o1 = 123, o2 = 456, o3 = 295, v1, v2, v3;
	int c1 = 20000, c2 = 20001, vc;

	v1 = o1 * o2;
	v2 = o3 / 2;
	v3 = o3 % 2;

	cout << o1 << " * " << o2 << " = " << setw(5) << v1 << endl;
	cout << o3 << " / 2 = " << setw(5) << v2 << endl;
	cout << o3 << " % 2 = " << setw(5) << v3 << endl;

	vc = c1 * c2;
	cout << endl << "BEWARE:" << endl;
	cout << setw(10) << c1 << " * " << setw(10) << c2 << " = " << vc << endl;
	cout << setw(10) << vc << " * " << setw(10) << 10 << " = " << vc * 10 << endl;
	system("pause");
}