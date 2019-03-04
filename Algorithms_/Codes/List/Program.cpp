#include <iostream>

#include "List.h"
#include"Node.h"

using namespace std;

int main(void)
{
	List* list = new List();

	for (int i = 0; i < 10; i++)
	{
		list->AddNode(i + 1);
	}

	cout << list->ToString();

	

	cout << endl << endl << "==========================" << endl << endl;

	cout << list->DeleteLastNode()->GetValue();

	cout << endl << endl << "==========================" << endl << endl;

	cout << list->DeleteLastNode()->GetValue();

	cout << endl << endl << "==========================" << endl << endl;

	cout << list->ToString();


	getchar();

	return (0);
}
