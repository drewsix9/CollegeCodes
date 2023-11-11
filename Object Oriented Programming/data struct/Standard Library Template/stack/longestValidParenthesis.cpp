#include <iostream>
#include <stack>
#include <string>

using namespace std;

int longestValidParentheses(string &s) {
  int res = 0;
  stack<int> stk;
  stk.push(-1); // Push -1 onto the stack as a starting point

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      stk.push(i); // Push the index of an opening parenthesis onto the stack
    } else {       // s[i] == ')'
      stk.pop();   // Pop the corresponding opening parenthesis index
      if (stk.empty()) {
        stk.push(i); // Push the current closing parenthesis index as a new starting point
      } else {
        res = max(res, i - stk.top()); // Update the result by calculating the length of the valid parentheses substring
      }
    }
  }

  return res;
}

int main() {
  string str = ")()())";
  cout << longestValidParentheses(str) << endl;

  return 0;
}