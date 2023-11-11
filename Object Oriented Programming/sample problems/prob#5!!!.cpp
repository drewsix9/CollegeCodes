/*
    You are given a list of integers, and you need to write a program to find the longest increasing subsequence (LIS) of the list. The LIS is the longest subsequence of the list in which the elements are in increasing order.

For example, given the list [5, 2, 8, 6, 3, 6, 9, 7], the LIS is [2, 3, 6, 9], because it is the longest subsequence of the list in which the elements are in increasing order.
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  vector<int> nums = {5, 2, 8, 6, 3, 6, 9, 7};
  unordered_map<int, int> pos;

  for (int i = 0; i < nums.size(); i++) {
    if (pos.find(nums[i]) != pos.end()) {
      if (pos.find(nums[i] - 1) == pos.end()) { // starting
        int count = 1;
        while (pos.find(nums[i] + count) != pos.end()) {
          count++;
        }
      }

    } else {
      pos[nums[i]] = i;
    }
  }

  cout << max << endl;
  return 0;
}