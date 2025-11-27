#include <iostream>
using namespace std;

int main(){
	int size, temp=0, res=INT_MIN;
	cout << "Input:" << endl;
	cin >> size;
	for(int i=0; i<size; i++){
		cin>>temp;
		res = temp > res ? temp : res;
	}
	cout << "Output:" << endl;
	cout << res;
}
