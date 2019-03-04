#include <iostream>
#include <string>

#include "KeyValue.h"

using namespace std;

int main()
{
	KeyValue* kv = new KeyValue(0, 1);

	KeyValue* child = kv->CreateNext(1, 2);

	for (int i = 2; i < 1000; i++)
	{
		child = child->CreateNext(i, i + 1);
	}

	cout << kv->GetAllKeyValues();

	getchar();

	return (0);
}
