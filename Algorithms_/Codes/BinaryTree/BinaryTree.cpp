#include "BinaryTree.h"

#include <iostream>

BinaryTree::BinaryTree()
{
	this->rootNode = nullptr;
}

void BinaryTree::Add(int value)
{
	BinaryTreeNode* currentNode = rootNode;


	BinaryTreeNode* prevNode = nullptr;

	bool rightChild = false;

	// Infinity War -> Thanos
	while (true)
	{
		// If root node is not initialized
		if (currentNode == nullptr)
		{
			// Set this node as binary node with given value
			currentNode = new BinaryTreeNode(value);

			// If old node is initialized because current node points to the null pointer (where we can insert our node)
			if (prevNode != nullptr)
			{
				// Defines if right or left child
				if (rightChild)
				{
					prevNode->SetRightChild(currentNode);
				}

				else
				{
					prevNode->SetLeftChild(currentNode);
				}
			}

			// In case that this binary tree has no nodes
			else
			{
				this->rootNode = currentNode;
			}

			break;
		}

		// In case that current node is initialized
		else
		{
			// If value has lower value than current node's key, then it goes to the left child of the current node
			if (value < currentNode->GetKey())
			{
				// old node is set as current node
				prevNode = currentNode;

				// and current node goes to his left child
				currentNode = currentNode->GetLeftChild();

				// right child is set false because value is lower than node's key
				rightChild = false;
			}

			// opposite way of algorithm above
			else if (value > currentNode->GetKey())
			{
				prevNode = currentNode;
				currentNode = currentNode->GetRightChild();
				rightChild = true;
			}

			// if value equals current node
			else if (value == currentNode->GetKey())
			{
				break;
			}
		}
	}
}

BinaryTreeNode* BinaryTree::Find(int value)
{
	// root node -> currentNode
	BinaryTreeNode* currentNode = this->rootNode;

	bool status = false;

	// checks value with current node's key
	while (currentNode != nullptr)
	{
		if (value < currentNode->GetKey())
		{
			currentNode = currentNode->GetLeftChild();
		}

		else if (value > currentNode->GetKey())
		{
			currentNode = currentNode->GetRightChild();
		}

		else if (value == currentNode->GetKey())
		{ 
			break;
		}
	}

	return currentNode;
}





