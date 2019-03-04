#pragma once
#include "Node.h"

#include <string>

class List
{
private:
	Node* head;
public:
	List();
	~List();
	Node* AddNode(int value);
	bool IsEmpty();
	Node* GetLastNode();
	std::string ToString();
	Node* DeleteLastNode();
};

