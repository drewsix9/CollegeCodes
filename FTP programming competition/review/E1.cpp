#include <iostream>
using namespace std;

int main(){
	int size, sum=0, temp;
	cout << "Input:\n";
	cin >> size;
	int arr[size];
	for(int i=0; i<size; i++){
		cin >> temp;
		sum += temp;
	}
	cout << "Output:\n" << sum;
}
