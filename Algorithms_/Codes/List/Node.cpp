#include "Node.h"



Node::Node(int value)
{
	this->value = value;
	this->next = nullptr;
}


Node::~Node()
{
}

Node* Node::GetNext()
{
	return this->next;
}

Node* Node::CreateNext(int value)
{
	this->next = new Node(value);
	return this->next;
}

int Node::GetValue()
{
	return this->value;
}

void Node::DeleteNext()
{
	delete this->next;
	this->next = nullptr;
}
