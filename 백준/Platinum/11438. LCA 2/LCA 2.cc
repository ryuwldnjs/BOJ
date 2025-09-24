#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adj;
int depth[100000+1], parent[100000+1][18];//parent[u][i] : u의 2^i번째 부모 
int n,a,b,m;

void dfs(int now){ //각 노드별 깊이 설정 
	for(int i=0;i<adj[now].size();i++){
		int next = adj[now][i];
		
		if(depth[next] == -1){
			parent[next][0] = now;
			depth[next] = depth[now] + 1;
			dfs(next);	
		}
	}
}

int LCA(int a, int b){
	if(depth[a] < depth[b]) swap(a,b);//항상 a가 더 깊거나 같도록 
	int diff = depth[a] - depth[b];
	
	//a와b의 depth을 동일하게 맞춰줌 
	for(int i=0;diff;i++){
		if(diff %2) a = parent[a][i];
		diff/=2;
	}
	
	//아직도 a,b의 공통조상을 찾지 못했다면?
	if(a!=b){		
		for(int i=17;i>=0;i--){
			if(parent[a][i] != -1 && parent[a][i]!=parent[b][i]){
				//a와 b의 공통조상을 찾기 직전까지 올라가기 
				a = parent[a][i];
				b = parent[b][i];
			}
		}
		
		//a는 현재 공통조상을 가지는 자식이므로, 한칸 더 올려줌 
		a = parent[a][0];
	}
	
	return a;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n;
	adj.resize(n+1);
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	fill(depth, depth+n+1, -1);
	fill(parent[0], parent[0]+(n+2)*18, -1);
	//for(int i=0;i<=n;i++) fill(parent[i], parent[i])
	depth[1] = 0;
	dfs(1);
	
	
	for(int j=0;j<18;j++){
		for(int i=1;i<=n;i++){
			if(parent[i][j] != -1)
				parent[i][j+1] = parent[parent[i][j]][j];
		}
	}
	
	
	cin>>m;
	while(m--){//쿼리
		cin>>a>>b;
		cout<<LCA(a,b)<<'\n';		 
	}
	
	return 0;
}