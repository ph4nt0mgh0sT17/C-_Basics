/*******************************
*   Using variable addresses   *
********************************/

#include <iostream>

int main()
{
	int i = 0; // Integer
	int &oi = i; // oi is link (address) to variable i
	oi = 2; // this will set i on value '2' because its address to this variable

	return 0;
}