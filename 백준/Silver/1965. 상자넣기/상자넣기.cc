#include <iostream>
#include <algorithm>
using namespace std;
vector<int> lis;
int n,a;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		auto target = lower_bound(lis.begin(), lis.end(), a);
		if(target == lis.end()) lis.push_back(a);
		else *target = a;
	}
	cout<<lis.size();
	return 0;
}