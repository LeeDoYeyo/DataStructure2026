// BinaryNode.h: 이진트리의 노드 클래스
#include "Record.h"
class BinaryNode : public Record
{
protected:
	BinaryNode* left;
	BinaryNode* right;
public:
	BinaryNode(const char* w = "", const char* m = "", const char* c = "")
		: Record(w, m, c), left(NULL), right(NULL) {
	}
	void		setLeft(BinaryNode* l) { left = l; }
	void		setRight(BinaryNode* r) { right = r; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }
	bool		isLeaf() { return left == NULL && right == NULL; }
};

