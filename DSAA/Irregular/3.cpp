/*
enter stack size: 3

(push)
input: 101.11
cannot push cause nay decimal

(push)
input: 101
palindrome
prime equivalet to decimal
5 is push to stack

(push)
input: 110
cannot push cause di palindrome
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isPalindrome(string str) {
  for (int i = 0; i < str.size() / 2; i++) {
    if (str[i] != str[str.size() - i - 1])
      return false;
  }
  return true;
}

bool isPrime(int num) {
  if (num <= 1)
    return false;
  for (int i = 2; i < num; i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}

int binToDeci(int num) {
  int pwr = 1, sum = 0;
  while (num > 0) {
    sum += num % 10 * pwr;
    pwr *= 2;
    num /= 10;
  }
  return sum;
}

bool hasDecimal(string &str) {
  size_t res = str.find_first_of('.');
  return res != string::npos;
}

void printStk(stack<int> &stk) {
  stack<int> stkCopy(stk);
  cout << "Current Stack: ";
  while (!stkCopy.empty()) {
    cout << stkCopy.top() << " ";
    stkCopy.pop();
  }
}

int main() {
  stack<int> stk;
  string num;
  int size, choice, bin, deci;
  cout << "Enter size of stack: ";
  cin >> size;
  while (1) {
    cout << "\n1. Push 2. Pop 3. Display 4. Exit: ";
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "Enter input: ";
      cin >> num;
      if (stk.size() >= size) {
        cout << "Stack is full" << endl;
        break;
      }
      bin = stoi(num);
      deci = binToDeci(bin);
      if (hasDecimal(num) || !isPrime(deci) || !isPalindrome(to_string(bin))) {
        cout << "Invalid input" << endl;
        break;
      }
      cout << "Pushed " << deci << " to stack." << endl;
      stk.push(deci);
      break;
    case 2:
      if (stk.empty()) {
        cout << "Stack is empty" << endl;
        break;
      }
      cout << "Popped " << stk.top() << " from stack." << endl;
      stk.pop();
      break;
    case 3:
      printStk(stk);
      break;
    case 4:
      return 0;
    }
  }
}