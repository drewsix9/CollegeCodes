#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *createTreeNode(int data)
{
    return new TreeNode{data, nullptr, nullptr};
}

int main()
{
    TreeNode *root = createTreeNode(1);

    root->left = createTreeNode(2);
    root->right = createTreeNode(3);

    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(5);
    root->right->left = createTreeNode(6);
    root->right->right = createTreeNode(7);

    root->left->right->left = createTreeNode(9);
    root->right->right->left = createTreeNode(15);

    queue<TreeNode *> myQueue; // declaring a queue named "myQueue" with type TreeNode*
    myQueue.push(root);        // pushing the root into the queue

    while (!myQueue.empty()) // while queue is not empty
    {
        TreeNode *ptr = myQueue.front(); // pointer that points to the first element in queue
        cout << ptr->data << " ";        // prints out the data
        myQueue.pop();                   // removes the first element in the queue

        if (ptr->left)
            myQueue.push(ptr->left); // if the left node is not NULL, add it into the queue
        if (ptr->right)
            myQueue.push(ptr->right); // if the right node is not NULL, add it into the queue
    }

    return 0;
}