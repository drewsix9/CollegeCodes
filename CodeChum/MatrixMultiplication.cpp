#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> MatrixMulti(vector<vector<int>> &arrA, vector<vector<int>> &arrB, int r1, int c1, int r2, int c2);
void display(vector<vector<int>> &arr);

int main() {
  int r1, c1, r2, c2;
  cout << "Enter the number of rows and columns of matrix A: ";
  cin >> r1 >> c1;
  vector<vector<int>> arrA(r1, vector<int>(c1));
  cout << "Enter the elements of matrix A:\n";
  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c1; j++) {
      cin >> arrA[i][j];
    }
  }
  cout << "Enter the number of rows and columns of matrix B: ";
  cin >> r2 >> c2;
  if (c1 != r2) {
    cout << "Error: The number of columns of matrix A must equal the number of rows of matrix B.";
    return 1;
  }
  vector<vector<int>> arrB(r2, vector<int>(c2));
  cout << "Enter the elements of matrix B:\n";
  for (int i = 0; i < r2; i++) {
    for (int j = 0; j < c2; j++) {
      cin >> arrB[i][j];
    }
  }
  cout << "The product of matrix A and matrix B is:\n";
  vector<vector<int>> res = MatrixMulti(arrA, arrB, r1, c1, r2, c2);
  display(res);
}

vector<vector<int>> MatrixMulti(vector<vector<int>> &arrA, vector<vector<int>> &arrB, int r1, int c1, int r2, int c2) {
  vector<vector<int>> res(r1, vector<int>(c2));
  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c2; j++) {
      res[i][j] = 0;
      for (int k = 0; k < c1; k++) {
        res[i][j] += arrA[i][k] * arrB[k][j];
      }
    }
  }
  return res;
}

void display(vector<vector<int>> &arr) {
  int row = arr.size();
  int col = arr[0].size();
  for (size_t i = 0; i < row; i++) {
    for (size_t j = 0; j < col; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}
