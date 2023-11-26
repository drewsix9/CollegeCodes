#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Function to find the largest submatrix with equal elements
int largestSubmatrix(vector<vector<int>> &matrix) {
  int rows = matrix.size();
  if (rows == 0) {
    return 0;
  }
  int cols = matrix[0].size();
  int largestSize = 0;

  // Map to store the count of submatrices with equal elements
  map<pair<int, int>, int> memo;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      for (int k = i; k < rows; k++) {
        for (int l = j; l < cols; l++) {
          int submatrixSize = (k - i + 1) * (l - j + 1);
          if (submatrixSize <= largestSize) {
            // Skip if the submatrix size is smaller than the largest found so far
            continue;
          }

          // Calculate the hash of the submatrix
          pair<int, int> hash = make_pair(i, j);
          hash.first = (hash.first * rows) + k;
          hash.second = (hash.second * cols) + l;

          // If the submatrix is already memoized, use the value from the memo
          if (memo.count(hash) > 0) {
            largestSize = max(largestSize, memo[hash]);
            continue;
          }

          // Check if all elements in the submatrix are equal
          int target = matrix[i][j];
          bool isSubmatrixEqual = true;
          for (int x = i; x <= k; x++) {
            for (int y = j; y <= l; y++) {
              if (matrix[x][y] != target) {
                isSubmatrixEqual = false;
                break;
              }
            }
            if (!isSubmatrixEqual) {
              break;
            }
          }

          // If all elements are equal, update the largestSize and memoize the result
          if (isSubmatrixEqual) {
            largestSize = max(largestSize, submatrixSize);
            memo[hash] = submatrixSize;
          }
        }
      }
    }
  }

  return largestSize;
}

int main() {
  int rows, cols;
  cout << "Enter the number of rows and columns: ";
  cin >> rows >> cols;

  // Input matrix
  vector<vector<int>> matrix(rows, vector<int>(cols));

  cout << "Enter the elements of the array:" << endl;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> matrix[i][j];
    }
  }

  int largestSubmatrixSize = largestSubmatrix(matrix);

  cout << "The largest submatrix with equal elements has size " << largestSubmatrixSize << endl;

  return 0;
}