#include <iostream>
#include <vector>

using namespace std;

bool isSymmetric(vector<vector<int>> &arr);

int main() {
  int n;
  cout << "Enter the size of the square array: ";
  cin >> n;
  vector<vector<int>> arr(n, vector<int>(n));
  cout << "Enter the elements of the array:\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  if (isSymmetric(arr)) {
    cout << "The array is symmetric.";
  } else {
    cout << "The array is not symmetric.";
  }
}

bool isSymmetric(vector<vector<int>> &arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    for (int k = i; k < n; k++) {
      if (arr[i][k] != arr[k][i]) {
        return 0;
      }
    }
  }
  return 1;
}
