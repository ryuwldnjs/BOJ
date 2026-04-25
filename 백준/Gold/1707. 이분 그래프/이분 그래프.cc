#include <iostream>
#include <vector>

using namespace std;
vector<vector<int> > adj;
int component[20000+5];
int t,v,e,a,b;
bool DFS(int now, int no){
	component[now] = no;
	for(int i=0;i<adj[now].size();i++){
		int next = adj[now][i];
		if(component[next] == no) return false;//이분그래프가 아닐경우
		if(component[next] == (no^1)) continue;//다으 노드가 반대편 컴포넌트에 포함될경우 
		else{
			if(!DFS(next, no^1)) return false; 
		} 
		
	}
	return true;
}
int main(){
	cin>>t;
	
	while(t--){
		cin>>v>>e;
		adj.clear(), adj.resize(v+1);
		fill(component, component+v+1, -1);
		
		for(int i=0;i<e;i++){
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		int flag = 1; 
		for(int i=1;i<=v;i++){
			if(component[i]==-1 && !DFS(i,0)){
				flag = 0;
				break;
			}
		}
		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}