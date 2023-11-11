#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool is_prime(int n)
{
  if (n <= 1)
  {
    return false;
  }
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      return false;
    }
  }
  return true;
}

void remove_prime_duplicates(vector<int> &v)
{
  unordered_set<int> primes;
  for (auto it = v.begin(); it != v.end();)
  {
    if (is_prime(*it))
    {
      if (primes.count(*it) == 0)
      {
        primes.insert(*it);
        ++it;
      }
      else
      {
        it = v.erase(it);
      }
    }
    else
    {
      ++it;
    }
  }
}

int main()
{
  vector<int> v = {10, 10, 2, 5, 2};
  remove_prime_duplicates(v);
  for (int i : v)
  {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}