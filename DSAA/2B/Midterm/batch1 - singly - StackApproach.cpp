
#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

map<char, int> priority = {
    {'*', 2},
    {'/', 2},
    {'+', 1},
    {'-', 1},
};

int evaluate(int x, int y, char c) {
  switch (c) {
  case '*':
    return x * y;
  case '/':
    return x / y;
  case '+':
    return x + y;
  case '-':
    return x - y;
  }
  return 0;
}

int main() {
  string str;
  cout << "\nEnter expression: ";
  cin >> str;
  stack<int> nums;
  stack<char> oper;

  for (int i = 0; i < str.size(); i++) {
    char c = str[i];
    if (c == '(') {
      oper.push(c);
    } else if (isdigit(c)) {
      nums.push(c - '0');
    } else if (c == ')') {
      while (oper.top() != '(') {
        int x, y;
        char op = oper.top();
        oper.pop();
        y = nums.top();
        nums.pop();
        x = nums.top();
        nums.pop();
        nums.push(evaluate(x, y, op));
      }
      oper.pop();
    } else if (c == '*' || c == '/' || c == '+' || c == '-') {
      while (!oper.empty() && oper.top() != '(' && priority[oper.top()] >= priority[c]) {
        int x, y;
        char op = oper.top();
        oper.pop();
        y = nums.top();
        nums.pop();
        x = nums.top();
        nums.pop();
        nums.push(evaluate(x, y, op));
      }
      oper.push(c);
    }
  }
  while (oper.size() != 0) {
    int x, y;
    char op = oper.top();
    oper.pop();
    y = nums.top();
    nums.pop();
    x = nums.top();
    nums.pop();
    nums.push(evaluate(x, y, op));
  }

  cout << "\nOutput: " << nums.top();
}