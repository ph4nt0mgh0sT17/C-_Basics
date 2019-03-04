#include "List.h"



List::List()
{
	this->head = nullptr;
}


List::~List()
{
}

Node* List::AddNode(int value)
{
	if (this->IsEmpty())
	{
		this->head = new Node(value);
		return this->head;
	}

	Node* lastNode = this->GetLastNode();

	lastNode->CreateNext(value);

}

bool List::IsEmpty()
{
	return (this->head == nullptr);
}

Node* List::GetLastNode()
{
	Node* node = this->head;
	while (node->GetNext() != nullptr)
	{
		node = node->GetNext();

	}
	return node;
}

std::string List::ToString()
{
	std::string result = "";

	Node* node = this->head;
	result+= std::to_string(node->GetValue()) + "; ";

	

	while (node->GetNext() != nullptr)
	{
		node = node->GetNext();
		result += std::to_string(node->GetValue()) + "; ";
	}

	return result;
}

Node* List::DeleteLastNode()
{
	Node* node = this->head;
	while (node->GetNext()->GetNext() != nullptr)
	{
		node = node->GetNext();

	}
	
	int valueLast = node->GetNext()->GetValue();
	node->DeleteNext();

	return new Node(valueLast);

	
}

