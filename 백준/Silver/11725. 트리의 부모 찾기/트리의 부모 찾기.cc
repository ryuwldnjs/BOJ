#include<iostream>
#include<vector>
using namespace std;
int n,a,b;
int parent[100000+5];
int visited[100000+5];
vector<int> linked[100000+5];

void dfs(int now){
	visited[now] = 1;
	for(int i=0;i<linked[now].size();i++){
		
		if(!visited[linked[now][i]]){
			dfs(linked[now][i]);
			parent[linked[now][i]] = now;
		} 
	}
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	
	parent[1] = 1;
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		linked[a].push_back(b);
		linked[b].push_back(a);
	}
	dfs(1);
	for(int i=2;i<=n;i++) cout<<parent[i]<<'\n';
	return 0;
}