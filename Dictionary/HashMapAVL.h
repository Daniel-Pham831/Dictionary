#include "AVL.h"
#define SIZE 1000

class HashMapAVL {
public:
	AVL HT[SIZE];
	int Length = SIZE;
	void insert(Word data);
	Word findWord(Word data);
	int getTotalWord();
private:
	void insertHelper(AVL HT[], Word data);
	int findHashCode(wstring value);
	int sumVocabLetter(wstring value);
};
