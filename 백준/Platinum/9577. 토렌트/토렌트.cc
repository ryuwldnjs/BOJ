#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> graph;
vector<int> l,r;
vector<bool> visited;
bool dfs(int x){
	if(visited[x]) return false;
	visited[x] = true;
	
	for(int y: graph[x]){
		if(r[y] == -1 || dfs(r[y])){
			l[x] = y;
			r[y] = x;
			return true;
		}
	}
	return false;
}

void solve(){
	int n,m;cin>>n>>m;
	graph = vector<vector<int>>(101);
	l = vector<int>(101, -1);
	r = vector<int>(101, -1);
	
	for(int i=0;i<m;i++){
		int t1,t2,a;
		cin>>t1>>t2>>a;
		vector<int> parts;
		for(int j=0;j<a;j++){
			int x; cin>>x;
			parts.push_back(x);
		}
		for(int t=t1;t<t2;t++){
			for(int part: parts){
				graph[t].push_back(part);
			}
		}
		
	}

	int match = 0;
	for(int t=0;t<=100;t++){
		visited = vector<bool>(101, false);
		if(dfs(t)) match++;
		if(match == n){
			cout<<t+1<<'\n';
			return;
		}
	}
	cout<<"-1\n";
}
int main(){
	cin.tie(0) -> sync_with_stdio(0);
	int t;cin>>t; while(t--) solve();
	return 0;
}