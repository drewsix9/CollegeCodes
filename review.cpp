

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int countDig(int n) {
  if (n <= 0) {
    return 0;
  }
  return 1 + countDig(n / 10);
}

int main() {
  cout << countDig(4316757);
}