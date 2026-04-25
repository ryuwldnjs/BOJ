#include <iostream>
#include <queue>
using namespace std;
priority_queue<pair<int,char> > pq;
int N, x;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>N;
	while(N--){
		cin>>x;
		if(x>0) pq.push({-x,'+'});//최소힙 
		else if(x<0) pq.push({x, '-'});
		if(x==0){
			if(pq.empty()){
				cout<<0<<'\n';
				continue;
			}
			
			x = pq.top().first;
			if(pq.top().second =='+') x*=-1;
			pq.pop();
			cout<<x<<'\n';
		}
	}
	return 0;
}