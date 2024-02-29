#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, a[1000000+50];
vector<int> vec;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		int llo = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
		if(llo == vec.size()){
			vec.push_back(a[i]);
		}
		else{
			vec[llo] = a[i];
		}
	}
	cout<<vec.size();
	return 0;
}