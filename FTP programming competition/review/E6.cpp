#include <bits/stdc++.h>
using namespace std;



int main(){
	int size;
	cout << "Input:\n";
	cin >> size;
	int arr[size];
	for(int i=0; i<size; i++){
		cin >> arr[i];
	}
	cout << "Output:\n";
	for(int i=0; i<size; i++){
		cout << (arr[i] % 2 ? "ODD" : "EVEN") << endl;
	}
}
