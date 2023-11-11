#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int isVisited = 0;
};

Node *createNode(int input)
{
    Node *node = new Node{input, nullptr, nullptr};
    return node;
}

void printNode(Node *root)
{
    queue<Node *> myqueue; // creates a queue named "myqueue" with Node* as type
    myqueue.push(root);    // pushing the root to the queue

    while (!myqueue.empty()) // while queue is not empty
    {
        Node *ptr = myqueue.front(); // a pointer that updates everytime the loop iterates
        cout << ptr->data << " ";
        myqueue.pop(); // removes the first element in queue

        if (ptr->left)
            myqueue.push(ptr->left);

        if (ptr->right)
            myqueue.push(ptr->right);
    }
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