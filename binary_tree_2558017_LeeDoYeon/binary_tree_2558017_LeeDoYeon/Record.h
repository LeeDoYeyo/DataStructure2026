// Record.h: 사전을 위한 레코드 클래스
#include <cstdio>
#include <cstring>
#define MAX_WORD_SIZE		40
#define MAX_MEANING_SIZE	200

class Record
{
protected:
	char	word[MAX_WORD_SIZE];		// 단어: 키 필드
	char	meaning[MAX_MEANING_SIZE];	// 의미
	char	category[50];				// 카테고리 (예: 명사, 동사, 형용사 등) - 필요에 따라 추가	
	int		searchCount;				// 검색 횟수
public:
	Record(const char* w = "", const char* m = "", const char* c = "") { set(w, m, c); }
	void set(const char* w, const char* m, const char* c) {
		strcpy_s(word, w);
		strcpy_s(meaning, m);
		strcpy_s(category, c);

		searchCount = 0;		// 검색 횟수 초기화
	}
	int compare(Record* n) { return compare(n->word); }
	int compare(char* w) { return strcmp(w, word); }
	int compareMeaning(char* m) { return strcmp(meaning, m); }
	char* getWord() { return word; }						// 단어 반환
	int getSearchCount() { return searchCount; }		 // 검색 횟수 반환
	void display() { printf(" %12s : %-20s [주제:%s] [검색:%d회]\n", word, meaning, category, searchCount); }
	void copy(Record* n) { strcpy_s(word, n->word); strcpy_s(meaning, n->meaning);  strcpy_s(category, n->category); searchCount = n->searchCount; }			// 
	void increaseSearchCount() { searchCount++; }		// 검색 횟수 증가
};