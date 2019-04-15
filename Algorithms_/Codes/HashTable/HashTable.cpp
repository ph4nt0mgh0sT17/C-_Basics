#include "HashTable.h"
#include <iostream>


HashTable::HashTable()
{
	this->hashNodes = new HashNode*[5];

	for (int i = 0; i < 5; i++)
	{
		this->hashNodes[i] = nullptr;
	}
	
}

void HashTable::Add(std::string value)
{
	int hashedValue = this->ToHash(value);

	

	HashNode* currentNode = this->hashNodes[hashedValue];

	if (currentNode == nullptr)
	{
		this->hashNodes[hashedValue] = new HashNode(value);
	}

	else
	{

		while (currentNode->GetNext() != nullptr)
		{
			currentNode = currentNode->GetNext();
		}

		currentNode->Add(value);
	}
}

int HashTable::ToHash(std::string value)
{
	int hashedValue = 0;
	for (int i = 0; i < value.length(); i++)
	{
		hashedValue += (int)(value.at(i));
	}

	hashedValue = hashedValue % 5;

	return hashedValue;
}

void HashTable::Print()
{
	HashNode* currentNode = nullptr;
	for (int i = 0; i < 5; i++)
	{
		currentNode = this->hashNodes[i];

		if (currentNode != nullptr)
		{
			std::cout << currentNode->GetValue() << "; ";

			while (currentNode->GetNext() != nullptr)
			{
				currentNode = currentNode->GetNext();
				std::cout << currentNode->GetValue() << "; ";
			}
		}

		else
		{
			std::cout << "NONE";
		}
		std::cout << std::endl;
		
	}
}

