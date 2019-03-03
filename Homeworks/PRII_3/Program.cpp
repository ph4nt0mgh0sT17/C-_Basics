#include <iostream>

#include "Invoice.h"

using namespace std;

int main()
{
	
	Invoice* invoice = new Invoice("David Miko", "Tvoja mama", "Tvoje Babicka", 690);

	invoice->AddItem("Intel Core i9-9900K", 14200);
	invoice->AddItem("AMD Ryzen 5 2600X", 5000);
	invoice->AddItem("Intel Core i7-8800K", 8500);


	cout << invoice->GetData();

	getchar();

	return (0);
}