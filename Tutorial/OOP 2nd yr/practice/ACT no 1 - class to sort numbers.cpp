#include <cstring>
#include <iostream>

using namespace std;

class SortNums {
private:
  int *arr;
  int size;

public:
  SortNums(); // constructor
  void sort();
  void display();
};

int main() {
  SortNums obj;
  obj.sort();
  obj.display();
  return 0;
}

SortNums::SortNums() { // constructor
  cout << "Constructor called" << endl;
  int buffer[100];
  char str[100];
  cout << "Enter elements of array: ";
  cin.getline(str, 100); // input numbers in a single line
  // tokenizing the input string
  char *token = strtok(str, " ");
  int n = 0;
  while (token != NULL) {
    buffer[n] = atoi(token); // convert string to integer
    token = strtok(NULL, " ");
    n++;
  }
  this->arr = new int[n]; // dynamic memory allocation
  this->size = n;
  for (int i = 0; i < this->size; i++) {
    this->arr[i] = buffer[i]; // this->array[i] is the class member while arr[i] is the parameter
  }
}

void SortNums::sort() {
  int temp;
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (arr[i] > arr[j]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  cout << "Successfully sorted numbers!" << endl;
}

void SortNums::display() {
  cout << "Output: ";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
