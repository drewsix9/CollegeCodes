#include <iostream>
#include <vector>

using namespace std;

void rotate(int n, vector<int> &arr);

int main() {
  int n, rotations;
  cout << "Enter size of array: ";
  cin >> n;
  vector<int> arr(n);
  cout << "Enter elements of array:\n";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << "Enter number of rotations: ";
  cin >> rotations;
  rotations %= n;
  rotate(rotations, arr);
  cout << "Rotated array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

void rotate(int k, vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < k; i++) {
    int temp = arr[n - 1];
    for (int j = n - 1; j > 0; j--) {
      arr[j] = arr[j - 1];
    }
    arr[0] = temp;
  }
}
