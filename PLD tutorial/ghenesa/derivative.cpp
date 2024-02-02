#include <bits/stdc++.h>

using namespace std;

/*
Input:3x^3+2x^2-2
Output:9x^2+4x

Input:3x^3+4xy^2
Output:9x^2+8xy+4y^2
*/

string parseDigits(string term, int constant) {
  string res;
  res += to_string(constant);
  res += term.substr(term.find('x'));
  return res;
}

string derive(string str) {
  int constant = 0;
  string res = "";
  for (size_t i = 0; i < str.size(); i++) {
    string term = "";
    while (i < str.size() && str[i] != '+' && str[i] != '-') {
      term += str[i];
      i++;
    }
    // i is currently at "+" or "-"
    size_t powerPos = term.find('^');
    size_t variableXPos = term.find('x');
    if (powerPos != string::npos) {
      if (term.find('2', powerPos) != string ::npos) {
        // if term has a power of 2
        constant = (term[0] - '0') * (term[term.size() - 1] - '0');
        if (constant >= 10) {
          term = parseDigits(term, constant);
        } else {
          term[0] = constant + '0';
        }
        term.erase(term.find('x') + 1, 2);
        res += term + str[i];
      } else {
        // if term has a power of 3 or more
        constant = (term[0] - '0') * (term[term.size() - 1] - '0');
        if (constant >= 10) {
          term = parseDigits(term, constant);
        } else {
          term[0] = constant + '0';
        }
        term[term.size() - 1] = ((term[term.size() - 1] - '0') - 1) + '0';
        res += term + str[i];
      }
    } else if (variableXPos != string::npos) {
      term.erase(term.size() - 1);
      res += term + str[i];
    }
    cout << "progress: " << res << endl;
  }
  if (res.back() == '+' || res.back() == '-') {
    res.pop_back();
  }
  return res;
}

int main() {
  string str;

  cout << "Enter an equation to derive: ";
  cin >> str;
  cout << "The derivative of " << str << " is " << derive(str) << endl;
  cin.ignore();
  cin.get();
}