#pragma once

class Tree {
	class Node {
	public:
		int val;
		Node *left,*right;
		Node(int d):val(d),left(nullptr),right(nullptr) {}
	};
public:
	Node *root;
	Tree():root(nullptr) {}
	void insert(Node *&n, int d);
	void display(Node *n,int space);
	void deleteNode(Node *&n, int d);
};
