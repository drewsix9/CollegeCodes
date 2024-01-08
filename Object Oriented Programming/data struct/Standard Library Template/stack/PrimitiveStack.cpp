#include <iostream>

using namespace std;

class PrimitiveStack {
public:
  int size, capacity, top, *arr;
  PrimitiveStack();
  ~PrimitiveStack();
  bool isFull() const;
  bool isEmpty() const;
  void push(int);
  void pop();
  int printTop();
  void print();
  void sort();
  void reverse();
  void clear();
};

PrimitiveStack::PrimitiveStack() {
  cout << "Enter stack size: ";
  cin >> capacity;
  top = -1;
  size = 0;
  arr = new int[capacity];
}

PrimitiveStack::~PrimitiveStack() {
  delete[] arr;
  cout << "\n[INFO] Successfully destroyed!";
}

bool PrimitiveStack::isFull() const {
  return size == capacity;
}

bool PrimitiveStack::isEmpty() const {
  return size == 0;
}

void PrimitiveStack::push(int num) {
  if (isFull()) {
    cout << "\n[WARNING] Stack is Full, Could not push";
    return;
  }
  arr[++top] = num;
  size++;
  cout << "\n[INFO] Successfully pushed!";
}

void PrimitiveStack::pop() {
  if (isEmpty()) {
    cout << "\n[WARNING] Stack is Empty, Could not pop";
    return;
  }
  top--;
  size--;
  cout << "\n[INFO] Successfully popped!";
}

int PrimitiveStack::printTop() {
  return arr[top];
}

void PrimitiveStack::print() {
  if (isEmpty()) {
    cout << "\n[WARNING] Stack is Empty, Could not print";
    return;
  }
  cout << "\nOuput: ";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
}

void PrimitiveStack::sort() {
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (arr[i] > arr[j]) {
        swap(arr[i], arr[j]);
      }
    }
  }
  cout << "\n[INFO] Successfully Sorted!";
}

void PrimitiveStack::reverse() {
  for (int i = 0; i < size / 2; i++) {
    swap(arr[i], arr[size - i - 1]);
  }
  cout << "\n[INFO] Successfully Reversed!";
}

void PrimitiveStack::clear() {
  top = -1;
  size = 0;
  cout << "\n[INFO] Successfully Cleared!";
}

int main() {
  PrimitiveStack stk;
  int choice, num;
  while (1) {
    cout << "\n\n0. Exit\n1. Push\n2. Pop\n3. Print Top\n4. Sort\n5. Reverse\n6. Clear\nEnter your choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      cout << "\nEnter number to push: ";
      cin >> num;
      stk.push(num);
      break;
    case 2:
      stk.pop();
      break;
    case 3:
      cout << "\nTop: " << stk.printTop();
      break;
    case 4:
      stk.sort();
      break;
    case 5:
      stk.reverse();
      break;
    case 6:
      stk.clear();
      break;
    default:
      cout << "\n[WARNING] Invalid Choice!";
    }
    stk.print();
  }
}