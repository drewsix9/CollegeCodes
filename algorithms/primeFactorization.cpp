#include <iostream>
#include <vector>

using namespace std;

vector<int> primeFactors(int num) {
  vector<int> res;
  for (int i = 2; i <= num; i++) {
    while (!(num % i)) {
      res.push_back(i);
      num /= i;
    }
  }
  return res;
}

int main() {
  while (1) {
    int num;
    cout << "\nEnter num: ";
    cin >> num;
    cout << "\nPrime Factors: ";
    vector<int> pf = primeFactors(num);
    for (int n : pf) {
      cout << n << " ";
    }
    cout << endl;
  }
}