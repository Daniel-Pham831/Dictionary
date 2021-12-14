//#include "Word.h"
//
//void Word::addMeaning(ListOfMeanings& meanings, wstring meaning) {
//	if (meanings == NULL) {
//		meanings = new Node(meaning);
//		pTail = meanings;
//		return;
//	}
//	else {
//		pTail->next = new Node(meaning);
//		pTail = pTail->next;
//	}
//}
//void Word::showListM(ListOfMeanings list) {
//	while (list != NULL) {
//		wcout << list->data << endl;
//		list = list->next;
//	}
//}
//Word::Word() {
//	this->vocab = NULL;
//	this->pTail = NULL;
//}
//void Word::addMeaning(wstring meaning) {
//	addMeaning(this->vocab, meaning);
//}
//void Word::show() {
//	showListM(this->vocab);
//}
//int sum3FirstLetter(wstring value) {
//	int pos = 0;
//	int sum = 0;
//	for (int i = 0; i < (int)value.length(); i++) {
//		if (value[i] == '@') {
//			pos = i;
//			break;
//		}
//	}
//	for (int i = 0; i < 3; i++) {
//		if (value[pos] > 'a' || value[pos] < 'z') {
//			pos++;
//			continue;
//		}
//		sum += (int)value[pos++];
//	}
//	return sum;
//}