#include <iostream>
#include <vector>

using namespace std;

vector<int> sortOdd(vector<int> nums) {
  vector<int> pos;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] % 2 != 0) {
      pos.push_back(i);
    }
  }

  for (int i = 0; i < pos.size() - 1; i++) {
    for (int j = i + 1; j < pos.size(); j++) {
      if (nums[pos[i]] > nums[pos[j]]) {
        swap(nums[pos[i]], nums[pos[j]]);
      }
    }
  }
  return nums;
}

int main() {
  vector<int> nums;
  cout << "Enter input: ";
  int temp;
  while (cin >> temp && temp != 0) {
    nums.push_back(temp);
  }

  cout << "\nOutput: ";
  for (int n : sortOdd(nums)) {
    cout << n << " ";
  }
  return 0;
}