/*Number of occurrence raman, then e tell asa dapit nga set nga ni occur ang number hahah dili counted ang usa ka occurance haha

  Set 1: 1 3 5 0
  Set 2: 1 9 0
  Set 3: 4 5 0

  Output:
  1 - Occured 2 times in Set/s: 1, 2
  5 - Occured 2 times in Set/s: 1, 3
*/

#include <cstring>
#include <iostream>

using namespace std;

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

  for (int i = 0; i < sets; i++) {
    cout << "Set " << i + 1 << ": ";
    for (int j = 0; j < eachSetCount[i]; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  int freq[100];
  memset(freq, 0, 100 * sizeof(int)); // sets all the values of freq to 0

  for (int i = 0; i < sets; i++) {
    for (int j = 0; j < eachSetCount[i]; j++) {
      freq[arr[i][j]]++; // increments the frequency of the number
    }
  }

  for (int i = 1; i < 100; i++) {
    if (freq[i] > 1) { // if the frequency is more than 1
      cout << i << " - Occured " << freq[i] << " times in Set/s: ";
      for (int j = 0; j < sets; j++) {
        for (int k = 0; k < eachSetCount[j]; k++) {
          if (arr[j][k] == i) {
            cout << j + 1 << " ";
            break;
          }
        }
      }
      cout << endl;
    }
  }
}