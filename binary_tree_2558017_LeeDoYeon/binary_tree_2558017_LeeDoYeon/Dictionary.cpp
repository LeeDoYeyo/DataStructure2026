#include "Dictionary.h"
#include <conio.h>


void help() {
	printf("[사용법] i-추가 d-삭제 w-단어검색 m-의미검색 p-출력 a-알파벳검색 t-최다검색 q-종료 =>");
}

// 이진 탐색 트리를 사용하는 영어 사전 프로그램 
void main()
{
	char	command;
	char	word[80];
	char	meaning[200];
	char	category[50];
	char	alphabet;
	Dictionary tree;

	do {
		help();
		command = _getche();
		printf("\n");
		switch (command) {
		case 'i':
			printf("  > 삽입 단어: ");
			gets_s(word);
			printf("  > 단어 설명: ");
			gets_s(meaning);
			printf("  > 주제 분류: ");
			gets_s(category);
			tree.insert(
				new BinaryNode(word, meaning, category));
			break;
		case 'd':
			printf("  > 삭제 단어: "); gets_s(word);
			tree.remove(word);
			break;
		case 'p':
			tree.printAllWords();
			printf("\n");
			break;
		case 'w':
			printf("  > 검색 단어: "); gets_s(word);
			tree.searchWord(word);
			break;
		case 'm':
			printf("  > 검색 의미: "); gets_s(word);
			tree.searchMeaning(word);
			break;
		case 't':
			tree.printMostSearchedWord();
			break;
		case 'a':
			printf("  > 시작 알파벳 입력: ");
			scanf_s(" %c", &alphabet, 1);
			getchar();
			tree.printWordsStartingWith(alphabet);
			break;
		}

	} while (command != 'q');
}