// BinaryTree.h: 이진트리 클래스
#include "BinaryNode.h"

class BinaryTree
{
protected:
	BinaryNode* root;
public:
	BinaryTree() : root(NULL) {}
	bool isEmpty() { return root == NULL; }
	void inorder(BinaryNode* node) {
		if (node != NULL) {
			if (node->getLeft() != NULL) inorder(node->getLeft());
			node->display();
			if (node->getRight() != NULL) inorder(node->getRight());
		}
	}
};