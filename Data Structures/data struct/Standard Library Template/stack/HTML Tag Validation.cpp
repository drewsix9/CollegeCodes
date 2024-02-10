#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  string caseInsensitive(string &str) {
    string res;
    for (char c : str) {
      if (isalpha(c)) {
        res += tolower(c);
      } else {
        res += c;
      }
    }
    return res;
  }

  bool isValid(string &str) {
    stack<string> stk;
    size_t l = 0, r = 0;
    do {
      l = str.find_first_of('<');
      r = str.find_first_of('>');
      string sub = str.substr(l + 1, r - l - 1);
      sub = caseInsensitive(sub);
      if (sub.find('/') != string::npos) {
        if (stk.empty()) {
          cout << "\nLeading closing tag....";
          return false;
        }
        sub.erase(0, 1);
        if (sub != stk.top()) {
          cout << "Pair is wrong!..." << sub;
          return false;
        }
        stk.pop();
      } else {
        stk.push(sub);
      }
      str = str.substr(r + 1);
    } while (r != string::npos);

    return true;
  }
};

int main() {
  Solution sol;
  string str = "<HTML><body><H1>Title</H1></BODY></html>";
  cout << "\nOutput: ";
  cout << ((sol.isValid(str)) ? "Valid!" : "Invalid!");
}