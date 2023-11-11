#include <iostream>
#include <vector>
#include <map>
/*
    sort the non-repeating numbers
    input: 5 10 2 7 5 2 2 8 1 12
    non-rep: 10 7 8 1 12
    output:5 1 2 7 5 2 2 8 10 12
*/
using namespace std;

int main()
{
  int temp;
  vector<int> nums, index;
  map<int, int> m;
  cout << "Enter inputs: ";
  while (cin >> temp && temp != 0)
  {
    nums.push_back(temp);
    m[temp]++;
  }

  for (int i = 0; i < int(nums.size()); i++)
  {
    if (m[nums[i]] == 1)
    {
      index.push_back(i);
    }
  }

  for (auto i = index.begin(); i != index.end(); i++)
  {
    for (auto j = i + 1; j != index.end(); j++)
    {
      if (nums[*i] > nums[*j])
      {
        swap(nums[*i], nums[*j]);
      }
    }
  }

  cout << "\nOutput: ";
  for (auto i : nums)
  {
    cout << i << " ";
  }

  return 0;
}
