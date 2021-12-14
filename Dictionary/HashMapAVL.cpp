#include "HashMapAVL.h"


void HashMapAVL::insert(Word data) {
	insertHelper(this->HT, data);
}
void HashMapAVL::insertHelper(AVL HT[], Word data) {
	int index = findHashCode(data);
	HT[index].addData(data);
}
int HashMapAVL::findHashCode(wstring value) {
	return sumVocabLetter(value) % this->Length;
}
int HashMapAVL::sumVocabLetter(wstring value) {
	int posBegin = 0;
	int posEnd = 0;
	int sum = 0;
	for (int i = 0; i < (int)value.length(); i++) {
		if (value[i] == '@') {
			posBegin = i + 1;
		}
		else if (value[i] == '/') { // tại vì chữ @asd /asd/ sau asd có Space
			posEnd = i - 1;
			break;
		}
		else if (value[i] == '\n') {
			posEnd = i - i;
		}
	}
	if (posEnd == 0)
		posEnd = value.length();
	for (int i = posBegin; i < posEnd; i++) {
		sum += (int)value[i];
	}
	return sum;
}
Word HashMapAVL::findWord(Word data) {
	int index = findHashCode(data);
	return this->HT[index].findData(data);
}
int HashMapAVL::getTotalWord() {
	int sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += this->HT[i].r->total;
	}
	return sum;
}