#include <iostream>
#include <unordered_set>
using namespace std;

bool isPrime(int num)
{
  if (num <= 1)
    return false;

  for (int i = 2; i < num; i++)
    if (num % i == 0)
      return false;

  return true;
}

int main()
{
  unordered_set<int> nums;
  cout << "Enter number of sets: ";
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int temp;
    while (cin >> temp && temp != 0)
    {
      if (isPrime(temp))
        nums.insert(temp);
    }
  }

  cout << "\nOutput: ";
  for (auto i : nums)
    cout << i << " ";

  return 0;
}