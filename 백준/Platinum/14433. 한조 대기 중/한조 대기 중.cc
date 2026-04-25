#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adj;
vector<int> troll;
bool visited[305];

int n,m,k1,k2, a,b;
int friendly_troll, enemy_troll;//각 팀별 트롤이 몇마린지 체크
 
bool DFS(int a){
	if(visited[a]) return false;
	visited[a] = true;
	
	for(int i=0;i<adj[a].size();i++){
		int b = adj[a][i];
		
		if(troll[b] == -1 || DFS(troll[b])){
			troll[b] = a;
			return true;
		}
	}
	return false;
}
int main(){
	cin>>n>>m>>k1>>k2;
	
	//우리팀 
	adj.resize(n+1), troll.resize(m+1, -1);
	for(int i=0;i<k1;i++){
		cin>>a>>b;
		adj[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		fill(visited, visited+n+1, false);
		if(DFS(i)) friendly_troll++;
	}
	
	
	//적팀 
	adj.clear(), troll.clear();
	adj.resize(n+1), troll.resize(m+1, -1);
	for(int i=0;i<k2;i++){
		cin>>a>>b;
		adj[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		fill(visited, visited+n+1, false);
		if(DFS(i)) enemy_troll++;
	}
	
	if(friendly_troll < enemy_troll)
		cout<<"네 다음 힐딱이";
	else
		cout<<"그만 알아보자";
	
	return 0;
} 