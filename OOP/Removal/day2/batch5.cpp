#include <iostream>
#include <unordered_map>
#include <vector>
/*
    sort the non-repeating numbers

    input: 5 10 2 7 5 2 2 8 1 12
    non-rep: 10 7 8 1 12
    output:5 1 2 7 5 2 2 8 10 12
*/
using namespace std;

int main() {
  int temp;
  vector<int> nums;
  unordered_map<int, int> freq; // [key, freq]
  cout << "Enter input: ";
  while (cin >> temp && temp != 0) {
    nums.push_back(temp);
    freq[temp]++;
  }

  vector<int> pos;
  for (int i = 0; i < nums.size(); i++) {
    if (!freq[nums[i]])
      pos.push_back(i);
  }

  for (int i = 0; i < pos.size(); i++) {
    for (int j = i + 1; j < pos.size(); j++) {
      if (nums[pos[i]] > nums[pos[j]]) {
        swap(nums[pos[i]], nums[pos[j]]);
      }
    }
  }

  cout << "\nOutput: ";
  for (int n : nums) {
    cout << n << " ";
  }

  return 0;
}