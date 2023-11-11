// Write a C++ program to implement a stack using an array with push and pop operations. Find the top element of the stack and check if the stack is empty or not.
#include <iomanip>
#include <iostream>

using namespace std;

class Stack {
  int MAX;
  int top;
  int arr[999];

public:
  Stack() {
    cout << "\nEnter size: ";
    cin >> MAX;
    top = -1;
  }

  bool isFull() { return top == MAX - 1; }
  bool isEmpty() { return top == -1; }
  int printTop() { return arr[top]; }

  void push(int num) {
    if (isFull()) {
      cout << "\nStack is Full!";
      return;
    }
    top++;
    arr[top] = num;
    cout << "\nSuccessfully pushed!";
  }

  void pop() {
    if (isEmpty()) {
      cout << "\nStack is empty";
      return;
    }
    top--;
  }
  void print() {
    cout << "\nStack: ";
    for (int i = top; i >= 0; i--) {
      cout << arr[i] << " ";
    }
  }

  void sort() {
    for (int i = top; i >= 0; i--) {
      for (int j = i - 1; j >= 0; j--) {
        if (arr[i] > arr[j]) {
          swap(arr[i], arr[j]);
        }
      }
    }
  }

  void reverse() {
    for (int i = top / 2; i >= 0; i--) {
      swap(arr[i], arr[top - i]);
    }
  }

  double avg() {
    double sum = 0;
    for (int i = top; i >= 0; i--) {
      sum += arr[i];
    }
    return sum / (top + 1);
  }
};

int main() {
  Stack stk;
  int num, choice = -1;
  while (1) {
    cout << "\n0 - Exit";
    cout << "\n1 - Push";
    cout << "\n2 - Pop";
    cout << "\n3 - Print";
    cout << "\n4 - Front";
    cout << "\n5 - Sort";
    cout << "\n6 - Reverse";
    cout << "\n7 - Average";
    cout << "\nEnter choice: ";
    cin >> choice;

    switch (choice) {
    case 0:
      cout << "\nExiting...";
      return 0;
    case 1:
      if (stk.isFull()) {
        cout << "\n[WARNING] Stack is full";
        break;
      }
      cout << "\nEnter num: ";
      cin >> num;
      stk.push(num);
      break;
    case 2:
      stk.pop();
      break;
    case 3:
      stk.print();
      break;
    case 4:
      cout << "\nFront: " << stk.printTop();
      break;
    case 5:
      stk.sort();
      break;
    case 6:
      stk.reverse();
      break;
    case 7:
      cout << "\nAverage: " << fixed << setprecision(2) << stk.avg();
      break;
    default:
      cout << "\n[WARNING] Wrong Input";
      break;
    }
    stk.print();
    cout << "\n__________________________________";
  }
}
