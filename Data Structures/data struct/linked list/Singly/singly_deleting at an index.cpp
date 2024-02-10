#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void printing(Node *head)
{
    cout << "\nOutput: ";
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    int temp, pos;
    cout << "Enter inputs: ";
    cin >> temp;

    Node *head = new Node{temp, nullptr};
    Node *ptr = head;

    while (cin >> temp && temp != 0)
    {
        ptr->next = new Node{temp, nullptr};
        ptr = ptr->next;
    }

    int count = 0;
    cout << "Enter index to delete: ";
    cin >> pos;
    ptr = head;
    while (count != pos - 1)
    {
        count++;
        ptr = ptr->next;
    }
    Node *temp2 = ptr->next->next;
    ptr->next = temp2;

    // free() the deleted node
    // and assign a nullptr

    printing(head);
}