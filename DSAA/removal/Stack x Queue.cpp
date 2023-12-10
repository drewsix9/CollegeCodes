
#include <iostream>
#include <vector>

using namespace std;

class StackQueue {
public:
  int _size;
  int posStk;
  int posQ;
  vector<int> arr;

public:
  StackQueue() : posStk(-1), posQ(-1) {
    cout << "Enter size of linked list: ";
    cin >> this->_size;
  }

  bool isEmpty() { return arr.empty(); }
  bool isFull() { return arr.size() == _size; }
  void push(int n);
  void pop();
  void enqueue(int n);
  void dequeue();
  void printLL();
};

void StackQueue::push(int n) {
  if (isFull()) {
    cout << "Linked list is full" << endl;
    return;
  }
  arr.insert(arr.begin(), n);
}

void StackQueue::pop() {
  if (isEmpty()) {
    cout << "Linked list is empty" << endl;
    return;
  }
  arr.erase(arr.begin());
}

void StackQueue::enqueue(int n) {
  if (isFull()) {
    cout << "Linked list is full" << endl;
    return;
  }
  arr.push_back(n);
}

void StackQueue::dequeue() {
  if (isEmpty()) {
    cout << "Linked list is empty" << endl;
    return;
  }
  arr.erase(arr.begin());
}

void StackQueue::printLL() {
  cout << "\n\ntop of stack/front of queue" << endl;
  cout << "        |" << endl;
  cout << "        v" << endl;
  cout << "Output: ";
  for (int n : arr) {
    cout << n << " ";
  }
}

int main() {
  StackQueue list;
  int choice, num;
  while (1) {
    cout << "\n\n-----Linked List Operations-----\n[0]: Exit\n[1]: Push\n[2]: Pop\n[3]: Enqueue\n[4]: Dequeue\nEnter choice: ";
    cin.clear();
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      cout << "Enter number to push: ";
      cin >> num;
      list.push(num);
      break;
    case 2:
      list.pop();
      break;
    case 3:
      cout << "Enter number to enqueue: ";
      cin >> num;
      list.enqueue(num);
      break;
    case 4:
      list.dequeue();
      break;
    default:
      cout << "Invalid choice" << endl;
    }
    list.printLL();
  }
}