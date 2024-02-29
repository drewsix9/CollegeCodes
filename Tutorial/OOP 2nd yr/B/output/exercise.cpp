#include <iostream>

using namespace std;

int main() {
  int n;
  cout << "Enter the number of elements: ";
  cin >> n;
  int *arr = new int[n];
  cout << "\nEnter " << n << " elements: ";
  for (int i = 0; i < n; i++) {
    cin >> *(arr + i);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (*(arr + i) < *(arr + j)) {
        int temp = *(arr + i);
        *(arr + i) = *(arr + j);
        *(arr + j) = temp;
      }
    }
  }
  cout << "\nAfter sorting numbers: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}