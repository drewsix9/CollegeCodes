#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *link;
};

int main()
{
    cout << "Enter inputs: ";
    Node *head = new Node;
    cin >> head->data;
    Node *ptr = head;

    int temp;
    while (cin >> temp && temp != 0)
    {
        ptr->link = new Node{temp, nullptr};
        ptr = ptr->link;
    }

    cout << "\nOutput: ";
    Node *newptr = head;
    while (newptr != nullptr)
    {
        cout << newptr->data << " ";
        newptr = newptr->link;
    }

    cout << "\nInserting at the end: ";
    cin >> temp;

    ptr->link = new Node{temp, nullptr};
    ptr = ptr->link;

    cout << "\nOutput: ";
    newptr = head;
    while (newptr != NULL)
    {
        cout << newptr->data << " ";
        newptr = newptr->link;
    }

    return 0;
}