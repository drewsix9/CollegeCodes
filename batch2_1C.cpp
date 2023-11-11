/*Input how many numbers:
Nya if Ang number is not a whole number , just print
If whole number then naay repeating digit na above 5 , convert to octal,
if whole number sya na way repeating dig , print the original number ra.
*/

#include <iostream>
#include <set>

using namespace std;

bool hasRepeatingAbove5(float num) {
  int n = (int)num;
  set<int> set;
  while (n > 0) {
    int rem = n % 10;
    if (rem > 5) {
      if (set.find(rem) != set.end()) {
        return 1;
      }
      set.insert(rem);
    }
    n /= 10;
  }
  return 0;
}

int toOctal(float num) {
  int n = (int)num;
  int sum = 0, prod = 0, pow = 1;
  while (n > 0) {
    prod = (n % 8) * pow;
    pow *= 10;
    sum += prod;
    n /= 8;
  }
  return sum;
}

int main() {
  float num;
  while (cin >> num && num != 0) {
    int temp = (int)num;
    if (num - temp == 0) { // whole
      if (hasRepeatingAbove5(num)) {
        cout << toOctal(num) << " ";
      } else {
        cout << (int)num << " ";
      }
    } else {
      cout << num << " ";
    }
  }
}