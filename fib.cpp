#include <bits/stdc++.h>
using namespace std;

int fib_helper(int n, map<int, int> memo) {
	if ( n == 0 || n == 1 ) return n;
	if (memo[n]) return memo[n];

	int res = fib_helper(n - 1, memo) + fib_helper(n - 2, memo);
	memo[n] = res;
	return res;
}

int fib(int n, map<int, int> memo) {
	return fib_helper(n, memo);
}

int fib_org(int n) {
	if (n == 0 || n == 1)return n;
	return fib_org(n - 1) + fib_org(n - 2);
}

int main() {
	map<int, int> memo;
	for (int i = 1; i < 100; i++) {
//		cout << fib(i, memo) << " ";
		cout << fib_org(i) << " ";
	}
}
