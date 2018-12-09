#include <iostream>

using namespace std;

// function KrkoskaMain works with COPY of int 'a' not with 'a' as itself
void krkoska_main(int a)
{
	a = 10;
	cout << a << endl;

	return;
}

void reference_main(int  &a)
{
	a = 10;
	cout << a << endl;

	return;
}

void pointer_main(int *a)
{
	*a = 20;
	cout << *a << endl;
	
	return;
}

int main(void)
{
	cout << "Hello, world!" << endl << endl;

	int a = 5; // initialize of integer 

	// pointer has everytime same size (4 B, 8 B and so on) as the original value

	int *p; // initialize of a pointer
	p = &a; // assign address of integer a (5) to pointer

	cout << "a = " << a << endl; // value of a
	cout << "address of pointer: " << &p << endl; // address of pointer as itself
	cout << "address of a in pointer: " << p << endl; //address of a in pointer p
	cout << "address of a: " << &a << endl; // adress of a
	cout << "value of a in pointer: " << *p << endl << endl; // value of pointer (pointer reference to a)
	
	// because it works only with copy

	krkoska_main(a); // 10
	cout << a << endl << endl; // 5

	// now it works with parameter a itself
	// address

	reference_main(a); // 10
	cout << a << endl << endl; // 10

	// now it works with pointer

	pointer_main(&a); // 20
	cout << a << endl << endl; // 20

	// we should use only reference...

	int num = 5;
	int *po = &num;
	int **q = &po;
	int ***o = &q;

	cout << *q << endl; // address of po
	cout << **q << endl << endl ; // value of a

	cout << *o << endl;
	cout << **o << endl;
	cout << ***o << endl;
	
	

	



	system("pause");
	return (0);
}
