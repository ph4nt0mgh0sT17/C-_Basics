#include <iostream>
#include "Dictionary.h"

int main(void)
{

	//int* a = new int(45);

	//Box<int>* box = new Box<int>(a);



	Dictionary<int, int>* dict = new Dictionary<int, int>();

	for (int i = 1; i <= 49; i++)
	{
		dict->Add(i, i*100);
	}

	dict->Remove(15);
	dict->Remove(25);

	vector<int>* keys = dict->Keys();
	vector<int>* values = dict->Values();



	for (int i = 0; i < keys->size(); i++)
	{
		cout << values->at(i) << "; ";
	}




	getchar();
	return (0);
}
