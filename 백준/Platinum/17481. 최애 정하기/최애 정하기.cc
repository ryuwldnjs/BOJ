#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

string namae;

vector<vector<int> > adj;
vector<int> favorite;
bool visited[1005];
map<string, int> name;

int n,m,x;
int cnt;// 최애를 찾은 멤버 수 
//이분매칭
bool DFS(int a){
	if(visited[a]) return false;
	visited[a] = true;
	
	for(int i=0;i<adj[a].size();i++){
		int b = adj[a][i];
		
		if(favorite[b] == -1 || DFS(favorite[b])){
			favorite[b] = a;
			return true;
		}
	}
	
	return false;
} 


int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	adj.resize(n+1), favorite.resize(m+1, -1);
	
	for(int i=1;i<=m;i++){
		cin>>namae;
		name[namae] = i; //각 아이돌 이름별 고유번호 달아주기 
	}
	
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=0;j<x;j++){
			cin>>namae;
			
			adj[i].push_back(name[namae]);
		}
	}
	
	for(int i=1;i<=n;i++){
		fill(visited, visited+n+1, false);
		if(DFS(i)) cnt++;
	}
	
	if(cnt == n) cout<<"YES";//n명 모두가 최애를 찾았다??
	else //모두가 그러하지 못했다..ㅠ 
		cout<<"NO\n"<<cnt;
	return 0;
}