#include <iostream>

using namespace std;

int main() {
  int arr[10] = {5, 1, 7, 2, 4, 8, 2, 9, 3, 10};
  for (int i = 0; i < 10 - 1; i++) {
    for (int j = i + 1; j < 10; j++) {
      if (arr[i] > arr[j]) {
        swap(arr[i], arr[j]);
      }
    }
  }
  cout << "Sorted: ";
  for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
  }
}