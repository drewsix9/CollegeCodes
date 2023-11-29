#include "tree.h"
#include <iostream>

using namespace std;

void Tree::insert(Node *&n, int d) {
	if(!n) {
		n = new Node(d);
		return;
	}
	if(d < n->val) {
		insert(n->left, d);
	} else if(d > n->val) {
		insert(n->right, d);
	} else {
		cout << "\nValue alread in tree";
	}
}
void Tree::display(Node *n,int space) {
	if(!n) {
		return;
	}
	display(n->right, space + 10);
	cout << endl;
	for(int i=10; i<space; i++) {
		cout << " ";
	}
	cout << n->val << endl;
	display(n->left, space + 10);

}
void Tree::deleteNode(Node *&n, int d) {
	if(!n) {
		cout << "Value doesnt exist in tree";
	}
	if(d > n->val) {
		deleteNode(n->right, d);
	} else if( d < n->val) {
		deleteNode(n->left, d);
	} else {
		if(!n->left && !n->right) {
			delete n;
			n = nullptr;
		} else if(n->left && !n->right) {
			n->val = n->left->val;
			delete n->left;
			n->left = nullptr;
		} else if(!n->left && n->right) {
			n->val = n->right->val;
			delete n->right;
			n->right = nullptr;
		} else {
			Node *minRight = n->right;
			while(minRight->left) {
				minRight = minRight->left;
			}
			int temp = minRight->val;
			n->val = temp;
			deleteNode(minRight, temp);
		}
	}
}

