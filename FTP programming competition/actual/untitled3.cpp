#include <bits/stdc++.h>
using namespace std;

bool rec(vector<int> &arr, int indx, int sum, int target) {
	if (indx >= arr.size())
		return false;

	if (sum == target) {
		return true;
	}

//	cout << arr[indx] << " ";
	rec(arr, indx + indx + 1, sum + arr[indx + indx + 1], target);
	rec(arr, indx + indx + 2, sum + arr[indx + indx + 2], target);
}

int main() {
	int n, target;
	cout << "Enter how many nodes: ";
	cin >> n;
	vector<int> arr(n, 0);
	cout << "Enter tree: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "Enter target sum: ";
	cin >> target;

//	queue<int> pos(arr.begin(), arr.begin()); // index is saved
//	while (!q.empty()) {
//		int sum = 0;
//		q.front();
//	}

	int sum = 0;
	cout << rec(arr, 0, sum, target);
}



