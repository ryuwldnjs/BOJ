#include <iostream>
using namespace std;
int n,m,a,prefix[1000000+5];
long long cnt[1000000+5];
long long ans;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		prefix[i] = (prefix[i-1] + a)%m;
		cnt[prefix[i]]++;
	}
	
	 
	for(int i=0;i<m;i++){
		if(cnt[i]) ans += (cnt[i]*(cnt[i]-1))/2;// nC2
	}
	ans += cnt[0];//자기자신으로도 나누어 떨어지는 경우
	cout<<ans; 
	return 0;
}