#include <iostream>

#include "KeyValues.h"


using namespace std;

int main()
{	
	KeyValues* kv = new KeyValues(20);
	
	for (int i = 0; i < 20; i++)
	{
		kv->CreateObject(i, i + 20);
	}

	cout << kv->GetInformation();
	
	cout << endl << "==============================================" << endl << endl;

	kv->RemoveObject(15);
	cout << kv->GetInformation();

	cout << endl << "==============================================" << endl << endl;

	kv->RemoveObject(18);
	cout << kv->GetInformation();

	getchar();

	return (0);
}
