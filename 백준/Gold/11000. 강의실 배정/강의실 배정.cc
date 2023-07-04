#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int n, x,y;
pair<int,int> time[200000+5];
int MAX = -1;
int main(){
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>x>>y;
		time[i] = {x,y};
	}
	sort(time, time+n);
	pq.push(0);
	
	for(int i=0; i<n;i++){
		int end = pq.top();
		if(end <= time[i].first){
			pq.pop();
		}
		pq.push(time[i].second);
		
		MAX = max(MAX, (int)pq.size());
	}
	
	cout<<MAX;
	return 0;
} 