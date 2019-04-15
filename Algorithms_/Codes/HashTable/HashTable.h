#pragma once

#include <string>
#include "HashNode.h"

class HashTable
{
private:
	HashNode** hashNodes;
public:
	HashTable();

	void Add(std::string value);

	int ToHash(std::string value);

	void Print();
};

