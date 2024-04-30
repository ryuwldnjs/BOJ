#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> pq;
int n,a,x;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		for(int i=0;i<a;i++){
			cin>>x;
			pq.push(x);
		}
		if(a) continue;
		
		if(pq.empty()) cout<<"-1\n";
		else{
			cout<<pq.top()<<'\n';
			pq.pop();
		}
	}
	return 0;
}