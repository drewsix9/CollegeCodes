#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, res = 1;
	cout << "Input:" << endl;
	cin >> n;
	for(int i=1;i <= n;i++){
		res *= i;
	}
	cout << "Output:" << endl;
	cout << res;
}
