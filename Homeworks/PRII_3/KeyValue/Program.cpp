#include <iostream>
#include <string>

#include "KeyValue.h"

using namespace std;

int main()
{
	KeyValue** keyValues = new KeyValue*[1000];

	for (int i = 0; i < 1000; i++)
	{
		keyValues[i] = new KeyValue(i, i + 1000);
		cout << "Key: " << to_string(keyValues[i]->GetKey()) << "; Value: " << to_string(keyValues[i]->GetValue()) << "\n";
	}

	getchar();

	return (0);
}
