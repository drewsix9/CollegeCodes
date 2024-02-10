#include <string>
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
    int temp;
    cout << "Enter inputs: ";
    Node *head = new Node;
    cin >> head->data;
    Node *temp_ptr = head;
    // while (cin >> temp && temp != 0)
    // {
    //     Node *ptr = new Node;
    //     temp_ptr->link = ptr;
    //     temp_ptr = ptr;
    //     ptr->data = temp;
    //     ptr->link = nullptr;
    // }

    // a more simplified one
    while (cin >> temp && temp != 0)
    {
        temp_ptr->link = new Node{temp, nullptr};
        temp_ptr = temp_ptr->link;
    }

    cout << "\nOutput: ";
    Node *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->link;
    }

    return 0;
}