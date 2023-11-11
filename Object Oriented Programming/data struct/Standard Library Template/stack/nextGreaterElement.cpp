#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreaterElement(vector<int> nums) {
  stack<int> stk;
  vector<int> res(nums.size(), -1); // Initialize all elements in res as -1
  stk.push(nums[nums.size() - 1]);

  for (int i = nums.size() - 2; i >= 0; i--) {
    while (!stk.empty() && stk.top() <= nums[i]) {
      stk.pop();
    }
    if (!stk.empty()) {
      res[i] = stk.top();
    }
    stk.push(nums[i]);
  }
  return res;
}

int main() {
  vector<int> nums = {3, 1, 7, 5, 9, 2, 6};
  vector<int> result = nextGreaterElement(nums);
  // Output: [5, 25, 25, -1, -1]

  cout << "\nOutput: ";
  for (int n : result) {
    cout << n << " ";
  }
}