#include "HashNode.h"



HashNode::HashNode(std::string value)
{
	this->value = value;
	this->next = nullptr;
}

void HashNode::Add(std::string value)
{
	HashNode* newNode = new HashNode(value);

	this->next = newNode;
}

HashNode* HashNode::GetNext()
{
	return this->next;
}

std::string HashNode::GetValue()
{
	return this->value;
}



