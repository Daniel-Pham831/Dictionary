#include "AVL.h"

AVL::AVL() {
	r = NULL;
}

int AVL::height(AVLTREE root) {
	if (root == NULL)
		return 0;
	else {
		return 1 + maxAB(height(root->left), height(root->right));
	}
}

int AVL::getBalance(AVLTREE r) {
	return height(r->left) - height(r->right);
}
void AVL::rotateRight(AVLTREE& r) {
	AVLTREE p = r->left;
	r->left = p->right;
	p->right = r;
	r->h = height(r);
	p->h = height(p);
	r = p;
}
void AVL::rotateLeft(AVLTREE& r) {
	AVLTREE p = r->right;
	r->right = p->left;
	p->left = r;
	r->h = height(r);
	p->h = height(p);
	r = p;
}
void AVL::rotateRightLeft(AVLTREE& r) {
	rotateRight(r->right);
	rotateLeft(r);
}
void AVL::rotateLeftRight(AVLTREE& r) {
	rotateLeft(r->left);
	rotateRight(r);
}

int AVL::maxAB(int a, int b) {
	if (a > b)
		return a;
	return b;
}

bool AVL::addData(Word data) {
	if (addDataHelper(this->r, data) == NULL)
		return false;
	return true;
}
Word AVL::findData(Word data) {
	return findDataHelper(this->r, data);
}
Word AVL::findDataHelper(AVLTREE r, Word data) {
	if (r == NULL) {
		return L"";
	}
	else if (getVocab(r->data).compare(data) == 0) {
		return r->data;
	}
	else {
		if (getVocab(r->data).compare(data) > 0)
			return findDataHelper(r->right, data);
		else {
			return findDataHelper(r->left, data);
		}
	}
}

Word AVL::getVocab(Word data) {
	int begin = 0;
	int end = 0;
	Word result;
	for (int i = 0; i < (int)data.length(); i++) {
		if (data[i] == '@')
			begin = i + 1;
		else if (data[i] == '/') {
			end = i - 1;
			break;
		}
		else if (data[i] == '\n') {
			end = i;
			break;
		}
	}

	for (int i = begin; i < end; i++) {
		result += data[i];
	}
	return result;
}

int AVL::getTotal(AVLTREE r) {
	if (r == NULL)
		return 0;
	else {
		return getTotal(r->left) + getTotal(r->right) + 1;
	}
}