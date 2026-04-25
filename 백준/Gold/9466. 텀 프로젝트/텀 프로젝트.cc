#include <iostream>
using namespace std;
int t,n,arr[100000+5];
bool visited[100000+5], done[100000+5];
int cnt;
void DFS(int now){
	if(visited[now]) return;
	visited[now] = true;
	
	int next = arr[now];
	
	DFS(next);
	if(!done[next]){
		for(int i=next;i!=now;i = arr[i]) 
			cnt++;
		cnt++;
	}
	done[now] = true;
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cnt=0;
		cin>>n;
		fill(visited, visited+n+1, false);
		fill(done, done+n+1, false);
		
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		for(int i=1;i<=n;i++){
			if(!visited[i])
			DFS(i);
		}
		
		cout<<n-cnt<<'\n';
	}
	return 0;
}