#include "myHeaderFiles/BaseN.h"
#include <iostream>

using namespace std;

class Stack {
private:
  int *arr;
  int capacity;
  int size;

public:
  Stack() : size(-1) {
    cout << "Enter size of stack: ";
    cin >> this->capacity;
    arr = new int[capacity];
  };
  void insert(int d);
  void pop();
  void displayBinary();
  void displayDecimal();
};

int main() {
  Stack stk;
  int n, c;
  while (1) {
    cout << "\n\n---Operations---";
    cout << "\n[0] - Exit";
    cout << "\n[1] - Insert";
    cout << "\n[2] - Pop";
    cout << "\n[3] - Display Binary";
    cout << "\n[4] - Display Decimal of Binary";
    cout << "\nChoose operation : ";
    cin >> c;
    switch (c) {
    case 0:
      return 0;
    case 1:
      cout << "\nEnter num to insert: ";
      cin >> n;
      while (!isBinary(n)) {
        cout << "Error: Input is not a binary!";
        cout << "\nEnter num to insert: ";
        cin >> n;
      }
      stk.insert(n);
      break;
    case 2:
      stk.pop();
      break;
    case 3:
      stk.displayBinary();
      break;
    case 4:
      stk.displayDecimal();
      break;
    default:
      break;
    }
  }
}

void Stack::insert(int d) {
  size++;
  if (size >= capacity) {
    cout << "\n[WARNING] Stack is full\n";
    size--;
    return;
  }
  arr[size] = d;
}

void Stack::pop() {
  if (size == 0) {
    cout << "\n[WARNING] Stack is empty";
    return;
  }
  size--;
}

void Stack::displayBinary() {
  cout << "\nStack (Binary): ";
  for (int i = 0; i <= this->size; i++) {
    cout << arr[i] << " ";
  }
}

void Stack::displayDecimal() {
  cout << "\nStack (Decimal): ";
  for (int i = 0; i <= this->size; i++) {
    cout << BintoDeci(arr[i]) << " ";
  }
}