#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
ll n,m,k,x,y;
ll answer;
vector<ll> diff;
int main(){
	cin>>n>>m>>k>>x>>y;
	answer = k * (x + y); // 대피선 없을때 운행시간 
	
	for(int i=0;i<n;i++){
		ll a,b;cin>>a>>b;
		diff.push_back(a*x - b*y); // 대피선 설치시 얻는 이득 
	}
	
	sort(diff.begin(), diff.end());
	for(int i=0;i<m;i++){
		answer += diff[i];
	}
	
	cout<<answer;
	return 0;
}