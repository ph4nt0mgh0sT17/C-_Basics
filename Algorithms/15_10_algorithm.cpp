#include <iostream>

using namespace std;

int main(void)
{
	cout << "Hello, world!" << endl << endl;

	int a = 5; // initialize of integer 

	int *p; // initialize of a pointer
	p = &a; // assign address of integer a (5) to pointer

	cout << "a = " << a << endl; // value of a
	cout << "address of pointer: " << &p << endl; // address of pointer as itself
	cout << "address of a in pointer: " << p << endl; //address of a in pointer p
	cout << "address of a: " << &a << endl; // adress of a
	cout << "value of a in pointer: " << *p << endl; // value of pointer (pointer reference to a)



	system("pause");
	return (0);
}
