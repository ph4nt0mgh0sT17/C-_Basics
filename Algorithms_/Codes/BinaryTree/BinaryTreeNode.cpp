#include "BinaryTreeNode.h"

BinaryTreeNode::BinaryTreeNode(int value)
{
	this->key = value;
}

void BinaryTreeNode::SetLeftChild(BinaryTreeNode* node)
{
	this->leftChild = node;
}

void BinaryTreeNode::SetRightChild(BinaryTreeNode* node)
{
	this->rightChild = node;
}

int BinaryTreeNode::GetKey()
{
	return this->key;
}

BinaryTreeNode* BinaryTreeNode::GetLeftChild()
{
	return this->leftChild;
}

BinaryTreeNode* BinaryTreeNode::GetRightChild()
{
	return this->rightChild;
}
