#include <bits/stdc++.h>
using namespace std;

class Tree {
	public:
		class Node {
			public:
				int val;
				Node* left;
				Node* right;
				Node(int val) {
					this->val = val;
					this->left = nullptr;
					this->right = nullptr;
				}
				Node(int val, Node* l, Node* r) {
					this->val = val;
					this->left = l;
					this->right = r;
				}
		};
		Node *head;
		Tree(int n) {
			this->head = new Node(n);
		}
		void insert(int n) {
			Node *ptr = this->head;
			Node *prev = nullptr;
			bool flag_left = 0;
			while(ptr) {
				prev = ptr;
				if(n < ptr->val) {
					ptr = ptr->left;
					flag_left = 1;
				} else {
					ptr = ptr->right;
				}
			}
			// ptr should be null
			if(flag_left == 1) {
				prev->left = new Node(n);
			} else {
				prev->right = new Node(n);
			}
		}
		void dfs() {
			queue<Node *> q;
			q.push(this->head);
			while(!q.empty()) {
				Node *top = q.front();
				cout << top->val << " ";
				q.push(top->left);
				q.push(top->right);
				q.pop();
			}
		}

};

int main() {
	Tree Bt = Tree(10);
	Bt.insert(8);
	Bt.insert(2);
	Bt.insert(3);
	Bt.insert(5);
	Bt.dfs();
}