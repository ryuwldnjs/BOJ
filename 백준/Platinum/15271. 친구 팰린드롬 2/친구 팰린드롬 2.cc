#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adj;
vector<int> match;
bool visited[205];
int n,m,a,b,cnt;
bool DFS(int a){
	if(visited[a]) return false;
	visited[a] = true;
	
	for(int i=0;i<adj[a].size();i++){
		int b = adj[a][i];
		
		if(match[b] == -1 || DFS(match[b])){
			match[b] = a;
			return true;
		}
	}
	return false;
}
int main(){
	cin>>n>>m;
	adj.resize(n+1), match.resize(n+1, -1);
	for(int i=0;i<m;i++){
		cin>>a>>b;
		if(a%2==b%2) continue;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int i=1;i<=n;i++){
		fill(visited, visited+n+1, false);
		if(DFS(i)) cnt++;
	}
	
	if(cnt<n) cout<<cnt+1;//로봇댄스 한명 가능 
	else cout<<cnt;
	return 0;
}