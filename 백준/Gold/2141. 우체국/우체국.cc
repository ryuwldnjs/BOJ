#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 
using pii=pair<long long,long long>;
vector<pii> info;
long long n,x,a;
long long l;
long long total_people;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>a;
		info.push_back({x,a});
		total_people += a;
	}
	sort(info.begin(), info.end());
	for(int i=0;i<info.size();i++){
		l += info[i].second;
		long long r = total_people - l;
		if(l >= r){
			cout<<info[i].first;
			return 0;
		}
	}
	return 0;
}