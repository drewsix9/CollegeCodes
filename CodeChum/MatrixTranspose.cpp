#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> transposedMatrix(vector<vector<int>> &arr);
void display(vector<vector<int>> &arr);

int main() {
  int row, col;
  cout << "Enter number of rows: ";
  cin >> row;
  cout << "Enter number of columns: ";
  cin >> col;
  vector<vector<int>> arr(row, vector<int>(col));
  cout << "Enter elements of matrix:\n";
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cin >> arr[i][j];
    }
  }
  cout << "Transposed matrix:\n";
  vector<vector<int>> res = transposedMatrix(arr);
  display(res);
}

vector<vector<int>> transposedMatrix(vector<vector<int>> &arr) {
  int row = arr.size();
  int col = arr[0].size();
  vector<vector<int>> res(col, vector<int>(row));
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      res[j][i] = arr[i][j];
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
