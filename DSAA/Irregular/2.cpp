/*

EXAM NILA RL

Ask for input:

(1)push
(2)pop
(3)display

for push, sort the decimal in ascending order
and for display, display the whole input or simply print the input.
*/

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void processInput(string &str) {
  size_t pointPos = str.find_first_of('.');
  if (pointPos == string::npos) {
    return; // if input has no decimal
  }
  sort(str.begin() + pointPos + 1, str.end()); // built in algo from <algorithm>, kapoy na bubble sort
}

stack<string> printStk(stack<string> &stk) {
  stack<string> stkCopy(stk);
  cout << "Current Stack: ";
  while (!stkCopy.empty()) {
    cout << stkCopy.top() << " ";
    stkCopy.pop();
  }
  cout << endl;
  return stk;
}

void processStackSorting(stack<string> &stk) {
  vector<string> vec;
  while (!stk.empty()) {
    vec.push_back(stk.top());
    stk.pop();
  }
  sort(vec.begin(), vec.end(), [](const string &a, const string &b) { // lambda function to sort the vector
    float aFloat = stof(a);
    float bFloat = stof(b);
    return aFloat < bFloat;
  });
  stack<string> sortedStk;
  for (auto itr = vec.rbegin(); itr != vec.rend(); ++itr) {
    sortedStk.push(*itr);
  }
  stk = sortedStk;
}

int main() {
  stack<string> stks;
  int size, choice;
  string str;
  cout << "Enter stack size: ";
  cin >> size;
  while (1) {
    cout << "\nEnter input: ";
    cin >> str;
    cout << "Commands: 1. Push 2. Pop 3. Display 4. Exit: ";
    cin >> choice;
    switch (choice) {
    case 1:
      if (stks.size() >= size) {
        break;
      }
      processInput(str);
      stks.push(str);
      processStackSorting(stks);
      cout << str << " pushed in to stack";
      break;
    case 2:
      if (stks.size() <= 0) {
        cout << "\nStack is empty!";
        break;
      }
      stks.pop();
      break;
    case 3:
      stks = printStk(stks);
      break;
    case 4:
      return 0;
    }
  }
}