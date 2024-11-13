#include <iostream>
#include <queue>
#include <stack>
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

int digitSum(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

class Stack {
public:
  int size;
  vector<int> vec;

  Stack() {
    cout << "Enter size of stack: ";
    cin >> this->size;
  }

  void push(float input) {
    int whole = (int)input;
    float flt = input - whole;
    if (flt > 0) {
      cout << "\nInput is has a floating point number";
      return;
    }
    if (vec.size() >= this->size) {
      cout << "\nStack is full!";
      return;
    }
    int digSum = digitSum(whole);
    if (isPrime(digSum)) {
      vec.push_back(whole);
      arrange();
    }
  }

  void pop() {
    if (vec.size() <= 0) {
      cout << "\nStack is already empty";
      return;
    }
    vec.pop_back();
  }

  void print() {
    for (int n : vec) {
      cout << n << " ";
    }
  }

  void arrange() {
    for (int i = 0; i < vec.size() - 1; i++) {
      for (int j = i + 1; j < vec.size(); j++) {
        if (vec[i] > vec[j])
          swap(vec[i], vec[j]);
      }
    }
  }
};

int main() {
  int choice;
  float num;
  Stack stk;
  while (true) {
    cout << "\n1. Push\n2. Pop\n3. Print\n4. Exit\nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "Enter number: ";
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
      return 0;
    default:
      cout << "Invalid choice!";
    }
  }
}