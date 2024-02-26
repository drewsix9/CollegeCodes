/*
Enter number of sets: 3

Set 1: 2 3 4 5 5 0
Set 2: 10 11 12 13 0
Set 3: 14 15 1 17 0

Output:
2 3 5 11 13 17 (union of prime numbers of the sets, printing only once)
*/

#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

bool isPrime(int n) {
  if (n == 1 || n == 0)
    return false;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int main() {
  int sets;
  cout << "Enter how many sets: ";
  cin >> sets;

  int **arr = new int *[sets];
  int *eachSetCount = new int[sets];
  for (int i = 0; i < sets; i++) {
    cout << "Enter set " << i + 1 << ": ";
    int num = 1;
    int count = 0;
    int temparr[100]; // temporary array to store the numbers
    while (1) {
      cin >> num;
      if (num == 0)
        break; // if the input is 0, it will break the loop
      temparr[count] = num;
      count++;
    }
    eachSetCount[i] = count;
    arr[i] = new int[count];                      // creates a new array with the size of count
    memcpy(arr[i], temparr, count * sizeof(int)); // copies temparr to arr[i]
  }

  int freq[100];
  memset(freq, 0, 100 * sizeof(int)); // sets all the values of freq to 0

  for (int i = 0; i < sets; i++) {
    for (int j = 0; j < eachSetCount[i]; j++) {
      if (isPrime(arr[i][j])) {
        freq[arr[i][j]]++;
      } // increments the frequency of the number
    }
  }

  cout << "\nOutput: ";
  for (int i = 0; i < 100; i++) {
    if (isPrime(i) && freq[i] > 0) {
      cout << i << " ";
    }
  }
}