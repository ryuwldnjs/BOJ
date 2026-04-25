#include <iostream>
#include <vector>
#define INF 1234567890
using namespace std;
vector<vector<pair<int,int> > > tree;
int depth[100000+5];
int parent[100000+5][18];// parent[u][i] : u의 2^i번째 부모 
int MIN[100000+5][18]; //어느 구간의 최소값 
int MAX[100000+5][18]; //최댓값 
int n,a,b,c,k;

//두 정점간의 경로중 최솟값,최댓값 찾기
// LCA 이용..2020/08/28 새벽3시21분 살려줘..
 
pair<int,int> LCA(int a, int b){
	int Max = -INF, Min = INF;
	if(depth[a] < depth[b]) swap(a,b);
	//항상 a가 깊거나 같도록
	
	int diff = depth[a] - depth[b];
	for(int i=0;diff;i++){
		if(diff%2) {
			Max = max(Max, MAX[a][i]);
			Min = min(Min, MIN[a][i]);
			a = parent[a][i];
		}
		diff/=2;
	}
	
	if(a != b){
		for(int i = 17; i>=0;i--){
			if(parent[a][i] != -1 && parent[a][i] != parent[b][i]){
				Max = max(Max, max(MAX[a][i],MAX[b][i]));
				Min = min(Min, min(MIN[a][i],MIN[b][i]));
				a = parent[a][i];
				b = parent[b][i];
			}
		}
		Min = min(Min, min(MIN[a][0], MIN[b][0]));
		Max = max(Max, max(MAX[a][0], MAX[b][0]));
	}
	
	
	return make_pair(Min, Max);
}

void DFS(int now){
	for(int i=0;i<tree[now].size();i++){
		pair<int,int> next = tree[now][i];
		if(depth[next.first]==-1){
			depth[next.first] = depth[now] + 1;
			parent[next.first][0] = now;
			MIN[next.first][0] = next.second;
			MAX[next.first][0] = next.second;
			DFS(next.first);
		}
	}
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n;
	fill(depth, depth+n+1, -1);
	tree.resize(n+1);
	for(int i=0;i<=n;i++){
		fill(parent[i], parent[i]+18, -1);
		fill(MIN[i], MIN[i]+18, INF);
		fill(MAX[i], MAX[i]+18, -INF);
	}
	
	for(int i=1;i<n;i++){
		cin>>a>>b>>c;
		tree[a].push_back({b,c});
		tree[b].push_back({a,c});
	}
	depth[1] = 0;
	DFS(1); //깊이 설정 
	
	for(int j=0;j<18;j++)
		for(int i=1;i<=n;i++)
			if(parent[i][j] != -1){
				parent[i][j+1] = parent[parent[i][j]][j];
				MIN[i][j+1] = min(MIN[i][j], MIN[parent[i][j]][j]);
				MAX[i][j+1] = max(MAX[i][j], MAX[parent[i][j]][j]);
			}

	cin>>k;
	while(k--){
		cin>>a>>b;
		pair<int,int> tmp = LCA(a,b);
		cout<<tmp.first<<' '<<tmp.second<<'\n';
	}
	
	return 0;
}