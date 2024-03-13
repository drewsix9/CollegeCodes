#include <bits\stdc++.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  vector<string> vec;
  for (int i = 1; i < argc; i++) {
    vec.push_back(string(argv[i]));
  }
  cout << "The number of arguments is: " << vec.size() << endl;
  cout << "The arguments are: " << endl;
  for (auto i : vec) {
    cout << i << endl;
  }
}