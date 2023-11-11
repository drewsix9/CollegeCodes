#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reversal(string s) {
  string res;
  stack<char> stk;
  for (char c : s) {
    stk.push(c);
  }
  while (!stk.empty()) {
    res += stk.top();
    stk.pop();
  }
  return res;
}

int main() {
  string str = "helloworld";
  cout << reversal(str) << endl;
}