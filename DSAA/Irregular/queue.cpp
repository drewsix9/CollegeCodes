#include <iostream>
#include <queue>
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

class Queue {
public:
  int size;
  vector<int> vec;

  Queue() {
    cout << "Enter size of Queue: ";
    cin >> this->size;
  }

  void enqueue(float input) {
    int whole = (int)input;
    float flt = input - whole;
    if (flt > 0) {
      cout << "\nInput is has a floating point number";
      return;
    }
    if (vec.size() >= this->size) {
      cout << "\nQueue is full!";
      return;
    }
    int digSum = digitSum(whole);
    if (isPrime(digSum)) {
      vec.push_back(whole);
      arrange();
    }
  }

  void dequeue() {
    if (vec.size() <= 0) {
      cout << "\nQueue is already empty";
      return;
    }
    vec.erase(vec.begin());
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
  Queue stk;
  while (true) {
    cout << "\n1. Enqueue\n2. Dequeue\n3. Print\n4. Exit\nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "Enter number: ";
      cin >> num;
      stk.enqueue(num);
      break;
    case 2:
      stk.dequeue();
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