#include <iostream>

using namespace std;

void print(int size, int arr[100], int pos) {
  for (int i = 0; i < size; i++) {
    if (i == pos - 1) {
      continue;
    }
    cout << arr[i] << " - Index: " << i;
    if (i != size - 1) {
      cout << ", ";
    }
  }
  cout << endl;
}

int main() {
  int size, pos, val;
  int arr[100];
  cout << "Enter size of array: ";
  cin >> size;
  cout << "Enter elements: ";
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }
  cout << "Enter position to be deleted: ";
  cin >> pos;
  cout << "Array after deleting position:" << endl;
  print(size, arr, pos);
}