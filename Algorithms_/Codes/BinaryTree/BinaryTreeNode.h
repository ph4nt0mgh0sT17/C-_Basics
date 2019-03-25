#pragma once
class BinaryTreeNode
{
private:
	BinaryTreeNode* leftChild;
	BinaryTreeNode* rightChild;
	int key = -1;

public:
	BinaryTreeNode(int value);
	void SetLeftChild(BinaryTreeNode* node);
	void SetRightChild(BinaryTreeNode* node);

	int GetKey();
	BinaryTreeNode* GetLeftChild();
	BinaryTreeNode* GetRightChild();


};

