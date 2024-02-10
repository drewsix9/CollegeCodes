#include <deque>
#include <iostream>
#include <vector>

std::vector<int> maxSlidingWindow(const std::vector<int> &nums, int k) {
  std::vector<int> result;
  std::deque<int> window;

  for (int i = 0; i < nums.size(); ++i) {
    // Remove elements outside the current window from the front of the deque
    while (!window.empty() && window.front() <= i - k) {
      window.pop_front();
    }

    // Remove elements smaller than the current element from the back of the deque
    while (!window.empty() && nums[i] >= nums[window.back()]) {
      window.pop_back();
    }

    // Add the current element's index to the deque
    window.push_back(i);

    // If the window size is equal to k, the front of the deque contains the maximum element
    if (i >= k - 1) {
      result.push_back(nums[window.front()]);
    }
  }

  return result;
}

int main() {
  std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;

  std::vector<int> result = maxSlidingWindow(nums, k);

  std::cout << "Sliding Window Maximum: ";
  for (int num : result) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}