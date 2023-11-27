bool isPrime(int num) {
  if (num <= 1)
    return 0;
  if (num == 2 || num == 3) {
    return 1;
  }
  for (int i = 2; i < num / 2 + 1; i++) {
    if (!(num % i)) {
      return 0;
    }
  }
  return 1;
}

bool isComp(int num) {
  if (num == 1)
    return 1;
  if (num == 2 || num == 3) {
    return 0;
  }
  for (int i = 2; i < num / 2 + 1; i++) {
    if (!(num % i)) {
      return 1;
    }
  }
  return 0;
}