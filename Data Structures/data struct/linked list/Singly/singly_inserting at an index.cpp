#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *link;
};

void printing(Node *head)
{
    Node *ptr = head;
    cout << "\nOutput: ";   
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->link;
    }
}

int main()
{
    int temp;
    cout << "Enter inputs: ";
    cin >> temp;
    Node *head = new Node{temp, nullptr};
    Node *ptr = head;

    while (cin >> temp && temp != 0)
    {
        ptr->link = new Node{temp, nullptr};
        ptr = ptr->link;
    }

    printing(head);

    int ins, pos;
    cout << "\nInsert value: ";
    cin >> ins;
    cout << "Insert index: ";
    cin >> pos;

    int count = 0;
    ptr = head;
    while (count != pos - 1)
    {
        count++;
        ptr = ptr->link;
    }

    Node *newPtr = new Node;
    newPtr->data = ins;
    newPtr->link = ptr->link;
    ptr->link = newPtr;

    printing(head);

    return 0;
}