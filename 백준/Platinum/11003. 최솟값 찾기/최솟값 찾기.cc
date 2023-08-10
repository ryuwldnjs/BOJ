#include <iostream>
#include <queue>
#define INF 2000000000 
using namespace std; 


priority_queue<int, vector<int>, greater<int>> all, deleted;
int k[5000000+5];
int n,l;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>l;
	deleted.push(INF);
	for(int i=0;i<n;i++){
		cin>>k[i];
		all.push(k[i]);
		
		if(i-l>=0){
			deleted.push(k[i-l]);
		}
		
		while(all.top() == deleted.top()){
			all.pop();
			deleted.pop();
		}
		
		cout<<all.top()<<' ';
	}
	
	return 0;
}