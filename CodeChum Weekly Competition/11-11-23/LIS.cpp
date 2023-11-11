#include <iostream>
#include <vector>

using namespace std;

int main() {
  int size, num;
  cout << "Enter the number of integers in the list: ";
  cin >> size;
  vector<int> arr(size);
  cout << "Enter the integers:\n";
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }
  vector<int> dp(size, 1);
  int res = 1;
  for (int i = 1; i < size; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[i] > arr[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    res = max(res, dp[i]);
  }
  cout << "The length of the longest increasing subsequence is: " << res;
}
