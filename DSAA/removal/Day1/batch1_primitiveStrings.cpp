#include <iostream>
#include <string.h>

using namespace std;

class StackLL {
public:
  int size, capacity, top;
  double *arr;
  StackLL();
  bool isFull() const;
  bool isEmpty() const;
  void push(double);
  void pop();
  int printTop();
  void print();
};

bool isPrime(int num) {
  if (num <= 1)
    return false;

  for (int i = 2; i < num; i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}

int breakDown(int num) {
  int sum = 0;
  while (num != 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

bool bothPrime(char *str) {
  if (strchr(str, '.') == NULL) { // checks if it has no decimal point
    return false;
  }
  char *token = strtok(str, "."); // while loop below checks if the whole and decimal part are prime
  while (token != NULL) {
    if (!isPrime(breakDown(stoi(token)))) // stoi() converts string to integer
      return false;
    token = strtok(NULL, ".");
  }
  return true;
}

int main() {
  StackLL stk;
  char str[50], test[50];
  int choice;
  while (1) {
    cout << "\n0 - Exit\n1 - Push\n2 - Pop\n3 - Print\nEnter choice: ";
    cin >> choice;
    cin.ignore(); // clears the input buffer
    switch (choice) {
    case 0:
      return 0;
    case 1:
      if (stk.isFull()) {
        cout << "\n[WARNING] Stack is full!";
        break;
      }
      cout << "\nEnter number to push: ";
      fgets(str, 50, stdin);
      strncpy(test, str, 50); // purposely used a different string to avoid overwriting the original string
      while (!bothPrime(test)) {
        cout << "\n[WARNING] Did not meet the condition!\t Try again!";
        cout << "\nEnter input: ";
        fgets(str, 50, stdin);
        strncpy(test, str, 50); // purposely used a different string to avoid overwriting the original string
      }
      stk.push(stod(str)); // stod() converts string to double
      break;
    case 2:
      stk.pop();
      break;
    case 3:
      stk.print();
      break;
    default:
      cout << "\n[WARNING] Invalid Choice!";
      break;
    }
  }
}

StackLL::StackLL() {
  cout << "Enter stack size: ";
  cin >> capacity;
  cin.ignore(); // clears the input buffer
  top = 0;
  size = 0;
  arr = new double[capacity];
  cout << "Enter input: ";
  char str[50], test[50];
  fgets(str, 50, stdin);
  strncpy(test, str, 50); // purposely used a different string to avoid overwriting the original string
  while (!bothPrime(test)) {
    cout << "\n[WARNING] Did not meet the condition!\t Try again!";
    cout << "\nEnter input: ";
    fgets(str, 50, stdin);
    strncpy(test, str, 50); // purposely used a different string to avoid overwriting the original string
  }
  push(stod(str)); // stod() converts string to double
}

bool StackLL::isFull() const {
  return size == capacity;
}

bool StackLL::isEmpty() const {
  return size == 0;
}

void StackLL::push(double num) {
  arr[top++] = num;
  size++;
  cout << "\n[INFO] Successfully pushed!";
}

void StackLL::pop() {
  top--;
  size--;
  cout << "\n[INFO] Successfully popped!";
}

int StackLL::printTop() {
  return arr[top - 1];
}

void StackLL::print() {
  cout << "\nOutput: ";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  return;
}
