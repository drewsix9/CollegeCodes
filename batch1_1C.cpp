/*input kag 4 ka numbers nya dapat 2 ka composite ug 2 ka prime
nya sunod kay ma fraction dapat ang smallest prime / smallest composite
 ug largest prime / largest composite nya imo i add.*/

#include <iostream>

using namespace std;

int GCF(int a, int b) {
  for (int i = 2; i <= a && i <= b; i++) {
    if (a % i == 0 && b % i == 0) {
      return i;
    }
  }
  return 1;
}

bool isPrime(int num) {
  if (num <= 1)
    return 2;
  if (num == 2 || num == 3)
    return 1;

  for (int i = 2; i < num / 2 + 1; i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int p1, p2, c1, c2;
  cout << "\nEnter 2 primes: ";
  cin >> p1 >> p2;
  if (!(isPrime(p1) && isPrime(p2))) {
    return 1;
  }
  cout << "\nEnter 2 comp: ";
  cin >> c1 >> c2;
  if (!(!isPrime(c1) && !isPrime(c2))) {
    return 1;
  }

  int sPrime, bPrime, sComp, Bcomp;
  if (p1 > p2) {
    bPrime = p1;
    sPrime = p2;
  } else {
    bPrime = p2;
    sPrime = p1;
  }

  if (c1 > c2) {
    Bcomp = c1;
    sComp = c2;
  } else {
    Bcomp = c2;
    sComp = c1;
  }

  int gcf = GCF(sComp, Bcomp);
  int lcm = (sComp * Bcomp) / gcf;
  int l = (lcm / sComp) * sPrime;
  int r = (lcm / Bcomp) * bPrime;
  int nume = l + r;
  int deno = lcm;
  int div = GCF(nume, deno);

  cout << "\nResult: " << nume / div << "/" << deno / div;
}