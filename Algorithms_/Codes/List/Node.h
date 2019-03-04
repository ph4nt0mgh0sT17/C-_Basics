#pragma once
class Node
{
private:
	int value;
	Node* next;
public:
	Node(int value);
	~Node();
	Node* GetNext();
	Node* CreateNext(int value);
	int GetValue();
	void DeleteNext();
};

