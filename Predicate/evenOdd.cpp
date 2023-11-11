#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct isEven {
	bool operator()(int n) {
		return n%2==0;
	}
};

bool isOdd(int n) {
	return n%2;
}

int main() {
	vector<int> vec = {2,7,2,2,5,2,1,7,4,8};
	
	cout<<"Even: "<<count_if(vec.begin(),vec.end(),isEven())<<endl; // passed a functor type
	
	cout<<"Odd: "<<count_if(vec.begin(),vec.end(),isOdd)<<endl; // passed a raw function
	
	cout<<"Even lambda: "<<count_if(vec.begin(),vec.end(),[](int n){return !(n%2);}); // lambda expression as predicate
		
}
