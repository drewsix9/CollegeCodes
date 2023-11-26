#include <iostream>
#include <vector>

using namespace std;

void rotated(vector<vector<int>> &arr);
void display(const vector<vector<int>> &arr);

int main() {
  int row, col;
  cout << "Enter the number of rows and columns: ";
  cin >> row >> col;
  vector<vector<int>> arr(row, vector<int>(col));
  cout << "Enter the elements of the array:\n";
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cin >> arr[i][j];
    }
  }
  cout << "Original Matrix:\n";
  display(arr);
  cout << "Rotated Matrix:\n";
  rotated(arr);
  return 0;
}

void rotated(vector<vector<int>> &arr) {
  int row = arr.size();
  int col = arr[0].size();
  vector<vector<int>> rotated(col, vector<int>(row));
  for (size_t i = rotated.size() - 1; i >= 0; i--) {
    for (size_t j = 0; j < rotated[0].size(); j++) {
      rotated[i][j] = arr[j][i];
    }
  }
  display(rotated);
}

void display(const vector<vector<int>> &arr) {
  int row = arr.size();
  int col = arr[0].size();
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}
