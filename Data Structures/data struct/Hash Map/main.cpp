#include "hashmap.hcpp"
#include <iostream>

using namespace std;

bool hasDuplicate(string str) {
  HashMap map;
  for (char c : str) {
    if (map.get(c) != -1) {
      return true;
    }
    map.put(c, 1);
  }
  return false;
}

int main() {
  HashMap map;
  string str;
  cout << "Enter a string: ";
  getline(cin, str);
  cout << boolalpha << hasDuplicate(str) << endl;
}
