#include <iostream>
#include <vector>

using namespace std;

void generatePascal(int n);

int main() {
  int n;
  cout << "Enter the number of rows: ";
  cin >> n;
  cout << "Pascal's triangle:\n";
  generatePascal(n);
}

void generatePascal(int n) {
  vector<vector<int>> arr(n, vector<int>(n));
  arr[0][0] = 1;
  arr[1][0] = arr[1][1] = 1;
  for (int i = 2; i < n; i++) {
    arr[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}
