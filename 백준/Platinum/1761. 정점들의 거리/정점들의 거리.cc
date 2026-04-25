#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int,int> > > adj; 
int dist[40000+5]; //dist[i]: 루트에서 i까지의 거리 
int parent[40000+5][18]; //parent[u][i] : u의 2^i번째 부모
int depth[40000+5];
int n,m,a,b,c;
void dfs(int now){
	for(int i=0;i<adj[now].size();i++){
		int next = adj[now][i].first;
		
		if(depth[next] == -1){
			depth[next] = depth[now] + 1;
			parent[next][0] = now;
			dist[next] = dist[now] + adj[now][i].second;
			//루트로부터 누적 거리
			
			dfs(next);
		}
		
	}
}

int LCA(int a, int b){
	if(depth[a] < depth[b]) swap(a,b);
	//항상 a가 더 깊거나 같도록
	int diff = depth[a] - depth[b];
	
	//ex) 깊이차이가 11일경우
	//이진수로 1011이므로, 비트가 1인경우일때만 계산해주면 된다. 
	for(int i=0;diff;i++){
		if(diff%2) a = parent[a][i];
		diff/=2;
	}

	
	//않이 이래도 같지 않다고? 
	if(a!=b){
		for(int i = 17; i>=0; i--){
			if(parent[a][i] != -1 && parent[a][i] != parent[b][i]){
				a = parent[a][i];
				b = parent[b][i];
			}
		}
		
		//여기까지 구한a는 공통조상의 바로밑 자식이므로 한칸 더 올려줌 
		
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
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	fill(depth, depth+n+1, -1);
	fill(parent[0], parent[0] + (n+1)*18, -1);
	
	depth[1] = 0;
	dfs(1);//임의로 1을 루트로 지정 
	
	
	
	for(int j=0;j<18;j++){
		for(int i=1;i<=n;i++){
			if(parent[i][j]!=-1)
				parent[i][j+1] = parent[parent[i][j]][j];
		}
	}
	cin>>m;
	while(m--){
		cin>>a>>b;
		
		int w = LCA(a,b);//공통 조상 찾기
		int answer = dist[a] + dist[b] - 2*dist[w];
		cout<<answer<<'\n';
		
		 
	}
	return 0;
} 