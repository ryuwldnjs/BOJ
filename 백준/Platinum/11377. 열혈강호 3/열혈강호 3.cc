#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adj;
vector<int> work;

bool visited[1005];
int able[1005]; //able[i] : i번째 사람이 지금까지 할수있는 일 개수 
int n,m,k,x,y,answer;

bool DFS(int x){
	if(visited[x]) return false;
	visited[x] = true;
	
	for(int i=0;i<adj[x].size();i++){
		int y = adj[x][i];
		
		if(work[y] == -1 || DFS(work[y])){
			work[y] = x;
			return true;
		}
	}
	return false;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>m>>k;
	adj.resize(n+1);
	work.resize(m+1, -1);
	for(int i=1;i<=n;i++){
		cin>>x;
		while(x--){
			cin>>y;
			adj[i].push_back(y);
		}
	}
	
	for(int i=1;i<=n;i++){
		fill(visited, visited+n+1, false);
		if(DFS(i)){
			answer++;
		}
	}
	
	
	for(int i=1;i<=n;i++){
		fill(visited, visited+n+1, false);
		if(DFS(i)){
			answer++;
			k--;
		}
		if(k==0) break;
	}
	cout<<answer;
	return 0;
}