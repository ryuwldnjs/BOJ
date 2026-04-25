#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> pq;
int N, x;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>N;
	while(N--){
		cin>>x;
		if(x) pq.push(-x);
		else{
			if(!pq.empty()){
				x = -pq.top(), pq.pop();
				cout<<x<<'\n';
			}
			else cout<<0<<'\n';
		}
	}
	return 0;
}