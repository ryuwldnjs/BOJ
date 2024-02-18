#include <bits/stdc++.h>
using namespace std;
int Q,a,b,x,y;
int main(){
	cin>>Q;
	while(Q--){
		cin>>a>>b>>x>>y; //시간,시간,개수,개수 
		int time_b = b * y;
		int remain = x - time_b / a;
		if (a*x <= b*y ) cout<<b*y<<'\n';
		else if(remain%2) cout<<(x - remain/2)*a<<'\n';
		else cout<<time_b + (remain/2)*a<<'\n'; 
	}
	return 0;
}