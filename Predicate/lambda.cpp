#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//if you are given integers and you are to get their frequencies using a map,
//and you want to sort the map non-increasing order with respect to their frequencies
//how would you do it since a map cannot do random access iterator

int main() {
	int nums[11] = {1, 2, 3, 2, 1, 3, 3, 4, 5, 4, 4};
	vector<pair<int,int>> vec;
	map<int,int> freqMap;

	for(int n: nums) {
		freqMap[n]++;
	}

	copy(freqMap.begin(),freqMap.end(),back_inserter(vec));
	// either one works
//	for(auto map: freqMap) {
//		vec.emplace_back(make_pair(map.first,map.second));
//	}


	sort(vec.begin(),vec.end(),[](auto &a,auto &b) {
		return a.second > b.second;
	});

	for(auto i : vec) {
		cout<<i.first<<" : "<<i.second<<endl;
	}
}
