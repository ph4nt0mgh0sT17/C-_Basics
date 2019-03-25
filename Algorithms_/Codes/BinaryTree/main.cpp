#include <iostream>

#include "BinaryTree.h"

using namespace std;

void print(BinaryTreeNode* root)
{
	cout << root->GetKey()<<endl;
	if (root->GetLeftChild() != nullptr)
	{
		print(root->GetLeftChild());
	}
	if (root->GetRightChild() != nullptr)
	{
		print(root->GetRightChild());
	}
	

}

int main()
{
	BinaryTree* bt = new BinaryTree();

	bt->Add(10);

	BinaryTreeNode* root = bt->Find(10);

	bt->Add(5);
	bt->Add(35);
	bt->Add(25);
	bt->Add(7);
	bt->Add(24);
	print(root);


	getchar();
	return (0);
}
