#include <iostream>

using namespace std;

class Stack {
private:
  int *arr;
  int size;

public:
  Stack() {
    cout << "Enter size of stack: ";
    cin >> this->size;
    // allocate memory
    arr = new int[size];
    // pwede sd
    // arr = (int*)malloc(sizeof(int)*size);
  }
};

int main() {
}