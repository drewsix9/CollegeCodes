#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int input)
{
    Node *node = new Node{input, nullptr, nullptr};
    return node;
}

void printNode(Node *root)
{
    if (root == nullptr)
        return;

    printNode(root->left);
    printNode(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    root->left->right->left = createNode(9);
    root->right->right->left = createNode(15);

    printNode(root);

    return 0;
}