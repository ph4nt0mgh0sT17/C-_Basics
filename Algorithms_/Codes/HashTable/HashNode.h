#pragma once

#include <string>
class HashNode
{
private:
	std::string value;
	HashNode* next;
public:
	HashNode(std::string value);

	void Add(std::string value);

	HashNode* GetNext();
	std::string GetValue();
};

