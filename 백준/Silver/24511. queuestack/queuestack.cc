#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int n,m,x,isStack[100000+5], arr[100000+5];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>isStack[i];
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	for(int i=n-1;i>=0;i--)
		if(!isStack[i]) q.push(arr[i]);
	
	
	cin>>m;
	while(m--){
		cin>>x;
		q.push(x);
		cout<<q.front()<<' ';
		q.pop();
	}
	return 0;
}