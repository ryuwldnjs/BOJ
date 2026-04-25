#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,a[1000000+50];
vector<int> vec; 
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
/*	vec.push_back(a[0]);
	vec.push_back(a[1]);
	vec.push_back(a[2]);

	cout<<a<<vec.size();*/
//	cout<<vec.size();
	for(int i=0;i<n;i++){
		int llo = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
		if(llo == vec.size()){ //가장 큰 숫자일경우 
			vec.push_back(a[i]);
		}
		else{
			vec[llo] = a[i];
		}
	}
	cout<<vec.size();
//	for(int i=0;i<vec.size();i++) cout<<vec[i];
	return 0;
}