#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include <cstdio>
#include <stdio.h>
#include <fstream>

using namespace std;
typedef wstring Word;

class AVL{
	struct Node {
		int total;
		Word data;
		int h;
		Node* left;
		Node* right;

		Node() {
			this->h = 0;
			this->left = NULL;
			this->right = NULL;
		}
		Node(Word data) {
			this->data = data;
			this->h = 0;
			this->total = 1;
			this->left = NULL;
			this->right = NULL;
		}
		~Node() {}
	};
	typedef Node* AVLTREE;
public:
	AVLTREE r;
	AVL();
	int height(AVLTREE r);
	bool addData(Word data);
	Word findData(Word data);
	
private:
//	void deleteTree(AVLTREE& r);
	void rotateRight(AVLTREE& r);
	void rotateLeft(AVLTREE& r);
	void rotateRightLeft(AVLTREE& r);
	void rotateLeftRight(AVLTREE& r);
	int getTotal(AVLTREE r);

	AVLTREE addDataHelper(AVLTREE& r, Word data) {
		AVLTREE result;
		if (r == NULL) {
			r = new Node(data);
			return r;
		}
		else {
			if (getVocab(r->data).compare(data) == 0) {
				return NULL;
			}
			else if (getVocab(r->data).compare(data) < 0) {
				result = addDataHelper(r->right, data);
			}
			else {
				result = addDataHelper(r->left, data);
			}
		}
		r->total = getTotal(r);
		r->h = height(r);
		if (getBalance(r) == 2) {
			if (getBalance(r->left) == -1)
				rotateLeftRight(r);
			else
				rotateRight(r);
		}
		else if (getBalance(r) == -2) {
			if (getBalance(r->right) == 1)
				rotateRightLeft(r);
			else
				rotateLeft(r);
		}
		return result;
	}
	Word findDataHelper(AVLTREE r, Word data);
	Word getVocab(Word data);

	int maxAB(int a, int b);
	int getBalance(AVLTREE r);
	
};

