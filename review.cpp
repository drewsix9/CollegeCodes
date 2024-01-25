#include <cstring>
#include <iostream>

using namespace std;

int main() {
  cout << "Enter size: ";
  int size;
  cin >> size;
  int row, col;
  row = col = size;
  int arr[row][col];

  // Set all elements to 0
  memset(arr, 0, sizeof(arr));

  int num = 1;
  for (int i = 0; i < col; i++) // column
  {
    for (int j = 0; j < col - i; j++) // row
    {
      arr[i + j][i] = num++;
    }
  }

  cout << "Output: " << endl;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (arr[i][j] != 0) {
        cout << arr[i][j] << " ";
      }
    }
    cout << endl;
  }
  return 0;
}