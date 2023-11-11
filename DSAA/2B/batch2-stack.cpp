#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string freq(int num) {
  vector<int> v;
  string res;
  string str = to_string(num);
  map<int, int> freq;
  for (char c : str) {
    if (freq.find(c - '0') == freq.end()) {
      v.push_back(c - '0');
    }
    freq[c - '0']++;
  }
  for (int n : v) {
    res += to_string(freq[n]) + to_string(n);
  }
  return res;
}

int main() {
  stack<int> stk;
  int MAX, input;
  cout << "\nEnter max size: ";
  cin >> MAX;
  cout << "\nEnter input: ";
  cin >> input;
  cout << "\nOutput:\n";
  stk.push(input);
  while (MAX > 0) {
    int curr = stk.top();
    cout << freq(curr) << endl;
    stk.pop();
    stk.push(stoi(freq(curr)));
  }
}