#include <iostream>

using namespace std;

bool isPrime(int num) {
  if (num <= 1)
    return false;

  for (int i = 2; i < num; i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}

class StackLL2 {
public:
  int size, capacity, top;
  double *arr;
  StackLL2();
  bool isFull() const;
  bool isEmpty() const;
  void push(double);
  void pop();
  int printTop();
  void print();
};

int breakDown(int num) {
  int sum = 0;
  while (num != 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

bool bothPrime(string str) {
  if (str.empty())
    return false;
  auto point = str.find_first_of(".");
  string str1 = str.substr(0, point);
  string str2 = str.substr(point + 1);
  return (isPrime(breakDown(stoi(str1))) && isPrime(breakDown(stoi(str2))));
}

int main() {
  StackLL2 stack;
  int choice;
  string num;
  cout << "Enter input: ";
  cin >> num;
  while (!bothPrime(num)) {
    cout << "\n[WARNING] Did not meet the condition!\t Try again!";
    cout << "\nEnter input: ";
    cin >> num;
  }
  stack.push(stod(num));
  while (1) {
    cout << "\n0 - Exit\n1 - Push\n2 - Pop\n3 - Print\nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      if (stack.isFull()) {
        cout << "\n[WARNING] Stack Overflow!";
        break;
      }
      cout << "\nEnter num to push: ";
      cin >> num;
      if (!bothPrime(num)) {
        cout << "\n[WARNING] Did not meet the condition,\t Did not push!";
        break;
      }
      stack.push(stod(num));
      break;
    case 2:
      stack.pop();
      break;
    case 3:
      stack.print();
      break;
    default:
      cout << "\n[WARNING] Invalid choice!";
    }
  }
}

StackLL2::StackLL2() {
  size = 0;
  top = 0;
  cout << "\nEnter capacity: ";
  cin >> capacity;
  arr = new double[capacity];
}

bool StackLL2::isFull() const {
  return size == capacity;
}

bool StackLL2::isEmpty() const {
  return size == 0;
}

void StackLL2::push(double num) {
  arr[top++] = num;
  size++;
  cout << "\n[INFO] Successfully pushed!";
}

void StackLL2::pop() {
  if (isEmpty()) {
    cout << "\n[WARNING] Stack Underflow!";
    return;
  }
  top--;
  size--;
  cout << "\n[INFO] Successfully popped!";
}

int StackLL2::printTop() {
  return arr[top - 1];
}

void StackLL2::print() {
  cout << "\nOutput: ";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}
