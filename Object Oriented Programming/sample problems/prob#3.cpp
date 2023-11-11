/*
  You are given a list of integers, and you need to find the pair of integers that have the smallest absolute difference between them. For example, if the input list is [4, 2, 1, 3], the pair with the smallest absolute difference is (2, 3), with a difference of 1.
*/

#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>

using namespace std;

int main()
{
  int input;
  vector<int> nums;
  cout << "Enter inputs (0 to stop): ";
  while (cin >> input && input != 0)
  {
    nums.push_back(input);
  }

  if (nums.size() < 2)
  {
    cerr << "Error: Input list must have at least two elements" << endl;
    return 1;
  }

  int least = 99;
  int l, r;

  for (auto i = nums.begin(); i != nums.end(); i++)
  {
    for (auto j = i + 1; j != nums.end(); j++)
    {
      int diff = abs(*i - *j);
      if (diff < least)
      {
        least = diff;
        l = *i;
        r = *j;
      }
    }
  }

  cout << "(" << l << "," << r << ")"
       << " differece: " << least;

  return 0;
}