/***************
*   Constants  *
****************/

#include <iostream>
#include <string>





using namespace std;

// boolean - true or false
const bool _true = true;

// integer 
const int constant = 123;
const int integer = -987;
const double CPlanck = 6.6256e-34L; // for unacquainted CPlansk means Planck's constant

// Only one character, can be a number though
const char male_a = 'a';

// common text
const string _string = "constant string";

// simple array of float number
const float range[2] = { -20,60 };

// And arrays of roman and arabic values
const char roman_char[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
const int arabic_value[] = { 1, 5, 10, 50, 100, 500, 1000 };

int main()
{
	// Output of constants
	
	cout << _true << endl
		<< constant << endl
		<< integer << endl
		<< CPlanck << endl
		<< male_a << endl
		<< _string << endl;
   
	// outputs of values in arrays - need to use cycle
	// need to divide sizeof(arabic_value)/sizeof(int), because sizeof(arabic_value) 
	// would be 28 - 7*4, so we need to divide 28/4 (4 - sizeof(int), because int is 4 Bytes)
	for (int i = 0; i < sizeof(arabic_value)/sizeof(int); i++) 
		cout << "i= " << i
			<< ", roman: " << roman_char[i]
			<< ", arabic: " << arabic_value[i]
			<< endl;

	
	system("pause");
	

	return 0;
}
