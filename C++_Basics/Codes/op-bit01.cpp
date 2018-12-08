/*****************************
 *   Operations with bits    * 
 *****************************/

#include <iostream> //io stream - console
#include <iomanip> // io manipulation

using namespace std;

int main()
{
	int left1 = 1 << 1;
	int left7 = 1 << 7;
	cout.setf(ios::showbase); // show basic digital system

	// dec shows number in decimal system, hex changes decimal system to hex system (0x69 for ex.)
	cout << "1 << 1 = " << dec << setw(6) << left1 
		<< hex << setw(15) << left1 << endl;

	cout << "1 << 7 = " << dec << setw(6) << left7
		<< hex << setw(15) << left7 << endl;

	int right1 = -1 >> 1;
	int right8 = 512 >> 8;


	cout << "-1 >> 1 = " << dec << setw(6) << right1
		<< hex << setw(15) << right1 << endl;

	cout << "512 >> 8 = " << dec << setw(6) << right8
		<< hex << setw(15) << right8 << endl;

	/*
		Little explanation of bits operation

		Conjunction:
		Here we have two numbers - 13 and 6, need to convert to binary
		00001101
		00000110

		and where 1 and 1 match is value for us so in this case its only 4

		Disjunction is different:
		00001101
		00000110

		where is 1 and 0, 0 and 1, 1 and 1 its value for us so in this case its 15

		and last non:
		00001101
		00000110

		so where is 1 and 0 or 0 and 1 is value for us so in this case its 11
	*/
	int k = 13 & 6;
	int d = 13 | 6;
	int non = 13 ^ 6;

	cout << "13 & 6 = " << dec << setw(6) << k
		<< hex << setw(15) << k << endl;

	cout << "13 | 6 = " << dec << setw(6) << d
		<< hex << setw(15) << d << endl;

	cout << "13 ^ 6 = " << dec << setw(6) << non
		<< hex << setw(15) << non << endl;

	k = 2 & 1;
	d = 2 | 1;
	non = 2 ^ 1;

	cout << "2 & 1 = " << dec << setw(6) << k
		<< hex << setw(15) << k << endl;

	cout << "2 | 1 = " << dec << setw(6) << d
		<< hex << setw(15) << d << endl;

	cout << "2 ^ 1 = " << dec << setw(6) << non
		<< hex << setw(15) << non << endl;

	system("pause");

	return 0;
}

