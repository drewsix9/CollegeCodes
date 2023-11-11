#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool digitsUnique(int num) {
  unordered_set<int> set;
  while (num > 0) {
    if (set.find(num % 10) != set.end()) {
      return false;
    }
    set.insert(num % 10);
    num /= 10;
  }
  return true;
}

int main() {
  int temp;
  vector<int> nums;
  cout << "Enter input: ";
  while (cin >> temp && temp != 0) {
    nums.push_back(temp);
  }

  cout << "\nOutput: ";
  for (int n : nums) {
    cout << ((digitsUnique(n)) ? to_string(n) : "");
    cout << " ";
  }
  return 0;
}