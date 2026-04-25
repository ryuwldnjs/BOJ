#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> map[105];
bool canvisit[105][105]; //x에서 y로 갈수있는지
bool visited[105],ans;
int t,n;

int dist(int i,int j){
	return abs(map[i].first-map[j].first)+abs(map[i].second-map[j].second);
}

void dfs(int now){
	visited[now]=true;
	
	if(now==n+1){ //도착
		ans=true;
		return; 
	}
	for(int i=0;i<n+2;i++)
		if(canvisit[now][i]&&!visited[i]) dfs(i);
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>t;
	while(t--){
		for(int i=0;i<105;i++) fill(canvisit[i],canvisit[i]+105,false);
		fill(visited, visited+105, false);
		ans=false;
		
		cin>>n;
		for(int i=0;i<n+2;i++){
			cin>>map[i].first>>map[i].second;			
		}
		for(int i=0;i<n+2;i++){
			for(int j=0;j<n+2;j++){
				if(dist(i,j)<=1000) canvisit[i][j]=true; 
			}
		}
		
		dfs(0);
		if(ans) cout<<"happy\n";
		else cout<<"sad\n";
		
	}
	return 0;
}