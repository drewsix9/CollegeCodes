#include <iostream>

using namespace std;

void insertVal(int *size, int pos, int arr[100], int val) {
  for (int i = *(size)-1; i >= pos - 1; i--) {
    arr[i + 1] = arr[i];
  }
  arr[pos - 1] = val;
  *(size) += 1;
}

void sort(int size, int arr[100]) {
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void print(int size, int arr[100]) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
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
  cout << "Enter position to be inserted: ";
  cin >> pos;
  cout << "Enter value to be inserted: ";
  cin >> val;
  insertVal(&size, pos, arr, val);
  cout << "Array after insertion: ";
  print(size, arr);
  sort(size, arr);
  cout << "Array sorted: ";
  print(size, arr);
}
