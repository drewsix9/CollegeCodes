#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Node{
	long long data;
	Node *left;
	Node *right;
};



namespace BinaryTree{
	class BST{
		public:
			bool isEmpty() const {return root == NULL;}
			Node *insert(Node *, long long);
			Node *FindMin(Node *);
			Node *Delete(Node *, long long);
			bool Search(long long);
			int OddBinary(long long);
			void Preorder(Node *);
			void Inorder(Node *);
			void Postorder(Node *);
			void TreeTraversal();
			void display(Node *, int);
	};
};

Node *BinaryTree::BST::insert(Node *root, long long num){
	if(root == NULL){
		root = new Node();
		root->data = num;
		root->left = root->right = NULL;
	}
	else{
		if(num < root->data){
			root->left = insert(root->left, num);
		}
		else{
			root->right = insert(root->right, num);
		}
	}
	return root;
}

bool BinaryTree::BST::Search(long long num){
	bool found = false;
	if(isEmpty()){
		std::cout << "\nTree is empty!\n";
		return false;
	}
	Node *current;
	Node *parent;
	current = root;
	while(current != NULL){
		if(current->data == num){
			found = true;
			break;
		}
		else{
			parent = current;
			if(num > current->data){
				current = current->right;
			}
			else{
				current = current->left;
			}
		}
	}
	if(found == true){
		return true;
	}
}

Node *BinaryTree::BST::FindMin(Node *root){
	while(root->left != NULL){
		root = root->left;
	}
	return root;
}

Node *BinaryTree::BST::Delete(Node *root, long long num){
	if(root == NULL){
		return root;
	}
	else{
		if(num < root->data){
			root->left = Delete(root->left, num);
		}
		else{
			if(num > root->data){
				root->right = Delete(root->right, num);
			}
			else{
				if((root->left == NULL) && (root->right == NULL)){
					delete root;
					root = NULL;
				}
				else{
					if(root->left == NULL){
						Node *temp = root;
						root = root->right;
						delete temp;
					}
					else{
						if(root->right == NULL){
						Node *temp = root;
						root = root->left;
						delete temp;
						}
						else{
							Node *temp = FindMin(root->right);
							root->data = temp->data;
							root->right = Delete(root->right, temp->data);
						}
					}
				}
			}
		}
	}
return root;
}

int BinaryTree::BST::OddBinary( long long num){
	long long rem[100], error, count;
	count = 0;
	while(num){
		rem[count] = num % 10;
		num = num / 10;
		count++;
	}
	error = 0;
	for(int i=0; i<count; i++){
		if((rem[i] != 1) && (rem[i] != 0)){
			error++;
		}
	}
	if(error == 0){
		if(rem[0] == 1){
			return 1;
		}
		else{
			return -1;
		}
	}
	else{
		return -1;
	}
}

void BinaryTree::BST::Preorder(Node *root){
	if(root == NULL){
		return;
	}
	else{
		std::cout << root->data << " ";
		Preorder(root->left);
		Preorder(root->right);
	}
}

void BinaryTree::BST::Inorder(Node *root){
	if(root == NULL){
		return;
	}
	else{
	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
	}
}

void BinaryTree::BST::Postorder(Node *root){
	if(root == NULL){
		return;
	}
	else{
		Postorder(root->left);
		Postorder(root->right);
		cout << root->data << " ";
	}
}

void BinaryTree::BST:: TreeTraversal(){
	system("cls");
	char choice;
	while(1){
		cout << "-----Tree Traversal-----" << endl;
		cout << "[1]: Preorder" << endl;
		cout << "[2]: Inorder" << endl;
		cout << "[3]: Postorder" << endl;
		cout << "[4]: Exit" << endl;
		cout << "Choice: ";
		cin >> choice;
		switch(choice){
			case '1':
				cout << "\nPreorder: ";
				Preorder(root);
				cout << endl <<endl;
				break;
			case '2':
				cout << "\nInorder: ";
				Inorder(root);
				cout << endl << endl;
				break;
			case '3':
				cout << "\nPostorder: ";
				Postorder(root);
				cout << endl << endl;
				break;
			case '4':
				system("cls");
				std::cout << "Terminating Program......";
				exit(0);
				break;
			default:
				cout << "\nWrong Choice!\n\n";
				break;
		}
	}
}

void BinaryTree::BST::display(Node *ptr, int level){
	if(ptr != NULL){
		display(ptr->right, level+1);
		cout << endl;
		if(ptr == root){
			cout << "Root-> ";
		}
		else{
			for(int i=0; i<level; i++){
			cout << " ";
			}
		}
		cout<< ptr->data;
		display(ptr->left, level+1);
	}
}

int main(int argc, char** argv){
	BinaryTree::BST bst;
	char choice;
	long long num;
	cout << "---Creating Root Node---" << endl;
	bool done = false;
	while(!done){
		cout << "Enter binary number: ";
		cin >> num;
		if(bst.OddBinary(num) == 1){
			system("cls");
			root = bst.insert(root, num);
			bst.display(root, 1);
			done = true;
		}
		else{
			cout << "\nERROR 404: Odd Binary number not found!\n\n";
		}
	}
	cout << endl;
	while(1){
		cout << "\n---Binary Tree Operations---\n";
		cout << "[1]: Insert node\n";
		cout << "[2]: Delete node\n";
		cout << "[3]: Search\n";
		cout << "[4]: Tree Traversal\n";
		cout << "[5]: Exit\n";
		cout << "Choice: ";
		cin >> choice;
		switch(choice){
		case '1':
			std::cout << "\nEnter binary number: ";
			std::cin >> num;
			if(bst.OddBinary(num) == 1){
				if(bst.Search(num)){
					cout << "\nElement already inserted!\n";
				}
				else{
					if(num != 0){
						cout << endl;
						root = bst.insert(root, num);
						bst.display(root, 1);
						cout << endl << endl;
					}
					else{
						cout << "\nNumber is not an odd binary number!\n";
					}
				}		
			}
			else{
				cout << "\nNumber is not an odd binary number!\n";
			}
			break;
		case '2':{
			cout << "\nEnter a number: ";
			cin >> num;
			if(bst.Search(num)){
				cout << endl;
				root = bst.Delete(root, num);
				bst.display(root, 1);
				cout << "\n\n\nElement deleted!\n";
			}
			else{
				cout << "\nElement not found!\n";
			}
			break;
		}
		case '3':
			cout << "\nFind an element: ";
			cin >> num;
			if(bst.Search(num)){
				cout << "\nElement found!\n";
			}
			else{
				cout << "\nElement not found!\n";
			}
			break;
		case '4':
			bst.TreeTraversal();
			break;
		case '5':
			system("cls");
			cout << "Terminating Program......";
			exit(0);
			break;
		default:
			cout << "\nWrong Choice!\n";
			break;
		}
	}
	return 0;
}