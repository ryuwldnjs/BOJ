#include <iostream>
#include <vector>
using namespace std;
bool visited[105];
bool graph[105][105];
vector<bool> truth;

int n,m,a,k,ans;
void dfs(int now){
	visited[now] = true;
	for(int i=1;i<=100;i++){
		if(graph[now][i] && !visited[i]) dfs(i);
	}
}
int main(){
	cin>>n>>m;
	truth.resize(n+1);
	
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>k;
		truth[k] = true;
	}
	
	for(int i=1;i<=m;i++){ //파티 번호 
		cin>>a;
		for(int j=0;j<a;j++){
			cin>>k;
			graph[50 + i][k] = graph[k][50 + i] = true;
			
		}
	}
	
	for(int i=0;i<truth.size();i++){
		if(truth[i] && !visited[i]) dfs(i);
	}
	
	for(int i=1;i<=m;i++){
		if(!visited[50 + i]) ans++;
	}
	cout<<ans;
	return 0;
} 