#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  unordered_set<int> nums;
  cout << "Enter inputs (0 to stop): ";
  int temp;
  while (cin >> temp && temp != 0) {
    nums.insert(temp);
  }

  cout << "\nOutput: ";
  for (int n : nums) {
    cout << n << " ";
  }

  return 0;
}