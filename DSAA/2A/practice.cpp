#include <iostream>
#include <string>
#include <vector>

using namespace std;

// automatically pop if the top is a NOT Palindrome

class Stack {
  int MAX;
  vector<string> vec;

public:
  Stack() {
    cout << "\nEnter size: ";
    cin >> this->MAX;
  }

  bool isFull() {
    return vec.size() == this->MAX;
  }

  void push(string num) {
    vec.insert(vec.begin(), num);
    cout << "\n[INFO] Successfully pushed " << num;
    if (!isPalindrome(vec.front())) {
      pop();
      cout << "\n[WARNING] Popped due to constraints";
    }
  }

  void pop() {
    if (vec.empty()) {
      cout << "\n[WARNING] Stack is empty";
      return;
    }
    vec.erase(vec.begin());
    cout << "\n[INFO] Successfully popped";
  }

  void print() {
    cout << "\n      top";
    cout << "\n       |";
    cout << "\n       v";
    cout << "\nStack: ";
    for (string s : vec) {
      cout << s << " ";
    }
  }

  bool isPalindrome(string s) {
    if (s.size() <= 1) {
      return 1;
    }
    if (s.front() != s.back()) {
      return 0;
    }
    return isPalindrome(s.substr(1, s.size() - 2));
  }
};

int main() {
  Stack stk;
  string str;
  int choice;
  while (1) {
    cout << "\n\n0 - Exit";
    cout << "\n1 - Push";
    cout << "\n2 - Pop";
    cout << "\n3 - Print";
    cout << "\nEnter choice: ";
    cin >> choice;
    switch (choice) {
    case 0:
      return 0;
    case 1:
      if (stk.isFull()) {
        cout << "\n[WARNING] Stack is FUll!";
        break;
      }
      cout << "\nEnter string: ";
      cin >> str;
      stk.push(str);
      break;
    case 2:
      stk.pop();
      break;
    case 3:
      stk.print();
      break;
    }
    stk.print();
  }
}
