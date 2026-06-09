#pragma once
// Dictionary.h: 사전 클래스
#include "BinSrchTree.h"

class Dictionary : public BinSrchTree
{
public:
	void printAllWords() {
		printf("    >> 나의 단어장:\n");
		if (!isEmpty())
			inorder(root);
	}

	void searchWord(char* word) {
		BinaryNode* node = search(word);

		if (node != NULL) {

			printf("    >> ");
			node->display();
			node->increaseSearchCount();		// 검색 횟수 증가
		}
		else
			printf("    >> 등록되지 않은 단어: %s\n", word);
	}

	void searchMeaning(char* m) {
		BinaryNode* node = (isEmpty()) ? NULL : searchByMeaning(root, m);
		if (node != NULL) {
			printf("    >> ");
			node->display();
			node->increaseSearchCount();		// 검색 횟수 증가
		}
		else
			printf("    >> 등록되지 않은 의미: %s\n", m);
	}
	BinaryNode* searchByMeaning(BinaryNode* node, char* m) {
		if (node == NULL || node->compareMeaning(m) == 0)
			return node;

		BinaryNode* theNode = searchByMeaning(node->getLeft(), m);
		if (theNode != NULL) return theNode;

		return searchByMeaning(node->getRight(), m);
	}

	void printMostSearchedWord() {
		if (isEmpty()) {
			printf("사전이 비어 있습니다.\n");
			return;
		}

		BinaryNode* maxNode = findMostSearched(root);

		printf("\n===== 가장 많이 검색된 단어 =====\n");
		maxNode->display();
		printf("검색 횟수 : %d회\n", maxNode->getSearchCount());
	}
	BinaryNode* findMostSearched(BinaryNode* node) {
		if (node == NULL)
			return NULL;

		BinaryNode* maxNode = node;

		BinaryNode* leftMax = findMostSearched(node->getLeft());
		BinaryNode* rightMax = findMostSearched(node->getRight());

		if (leftMax != NULL &&
			leftMax->getSearchCount() > maxNode->getSearchCount())
			maxNode = leftMax;

		if (rightMax != NULL &&
			rightMax->getSearchCount() > maxNode->getSearchCount())
			maxNode = rightMax;

		return maxNode;
	}

	void printWordsStartingWith(char ch) {
		printf("\n[%c 로 시작하는 단어]\n", ch);
		printWordsStartingWith(root, ch);
	}
	void printWordsStartingWith(BinaryNode* node, char ch) {
		if (node == NULL)
			return;

		printWordsStartingWith(node->getLeft(), ch);

		if (node->getWord()[0] == ch)
			node->display();
			node->increaseSearchCount();		// 검색 횟수 증가

		printWordsStartingWith(node->getRight(), ch);
	}
};