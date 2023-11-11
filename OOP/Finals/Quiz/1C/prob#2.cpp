#include <iostream>
#include <string>

using namespace std;

int main() {
  string input, rev;
  cout << " Enter string: ";
  getline(cin, input);
  cout << "\nEnter string to reverse: ";
  cin >> rev;

  string rev2(rev.rbegin(), rev.rend());
  int n = rev.size();
  auto it = input.find(rev);
  while (it != string::npos) {
    input.replace(it, n, rev2);
    it = input.find(rev);
  }

  cout << "\nOutput: " << input;
}