//"Automatically pop the top element if it is a string and contains duplicate consecutive characters."

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Queue {
private:
  vector<string> v;
  int MAX;

public:
  Queue() {
    cout << "\nEnter queue size: ";
    cin >> MAX;
  }

  bool isFull() {
    return MAX == v.size();
  }
  bool isEmpty() {
    return v.empty();
  }
  void enqueue(string value) {
    v.push_back(value);
    cout << "\n[INFO] Enqueue Successful!";
  }
  void dequeue() {
    if (isEmpty()) {
      cout << "\n[WARNING] Queue is Empty, Cant Perform Dequeue";
      return;
    }
    v.erase(v.begin());
    cout << "\n[INFO] Dequeue Successful!";
  }

  string &front() {
    return v.front();
  }

  void print() {
    if (isEmpty()) {
      cout << "\n[WARNING] Queue is Empty, Cant Perform Print";
      return;
    }
    cout << "\n      front";
    cout << "\n        |";
    cout << "\n        v";
    cout << "\nOutput: ";
    for (string item : v) {
      cout << item << " ";
    }
  }

  bool hasDuplicaateConsecutive(string s) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == s[i + 1]) {
        return 1;
      }
    }
    return 0;
  }
};

int main() {
  Queue q;
  string str;
  int num, choice = -1;

  while (1) {
    cout << "\n\n0 - Exit";
    cout << "\n1 - Enqueue";
    cout << "\n2 - Dequeue";
    cout << "\n3 - Print";
    cout << "\n4 - Front";
    cout << "\nEnter Choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      if (q.isFull()) {
        cout << "\n[WARNING] Queue is Full1";
        break;
      }
      cout << "\nEnter string: ";
      cin >> str;
      q.enqueue(str);
      break;
    case 2:
      q.dequeue();
      break;
    case 3:
      q.print();
      break;
    case 4:
      cout << "\nFront: " << q.front();
      break;
    default:
      cout << "\nInvalid Input...\n\n";
      break;
    }
    while (q.hasDuplicaateConsecutive(q.front()) && !q.isEmpty()) {
      cout << "\n[WARNING] Duplicate consecutive characters found on front element";
      q.dequeue();
    }
    q.print();
  }
}