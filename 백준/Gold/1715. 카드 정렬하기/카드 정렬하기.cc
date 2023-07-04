#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int n,k,sum;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k;
		pq.push(k);
	}
	
	while(pq.size() > 1){
		int x = pq.top();
		pq.pop();
		int y = pq.top();
		pq.pop();
		sum += x+y;
		pq.push(x+y);
	}
	cout<<sum;
	return 0;
}