
#include "BinaryTreeNode.h"

class BinaryTree
{
private:
	BinaryTreeNode* rootNode;
public:
	BinaryTree();

	void Add(int value);

	BinaryTreeNode* Find(int value);
};

