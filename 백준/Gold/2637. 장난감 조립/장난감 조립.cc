#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int,int>;

vector<vector<pii>> need;
vector<vector<int>> list;
vector<int> indegree;
queue<int> q;
int n,m,x,y,k;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	need.resize(n+1);
	list.resize(n+1);
	for(int i=0;i<list.size();i++) list[i].resize(n+1);
	indegree.resize(n+1);
	
	while(m--){
		cin>>x>>y>>k;
		need[y].push_back({x, k});// 부품y가 k개만큼있어야 x를 만들 자격이 생김 
		indegree[x]++;
	}
	
	for(int i=1;i<=n;i++){
		if(indegree[i] == 0){//기본부품 
			q.push(i);
			list[i][i] = 1; //기본부품은 자기자신1개을 재료를 필요한다고 가정 
		}
	}
	
	while(!q.empty()){
		int now = q.front();
		q.pop();
		
		for(int i=0;i<need[now].size();i++){
			int next = need[now][i].first;
			int amount = need[now][i].second;
			
			for(int j=1;j<=n;j++)
				list[next][j] += amount * list[now][j];
			
			if(--indegree[next] == 0)
				q.push(next);
		}
	}
	for(int i=1;i<n;i++)
		if(list[n][i]) cout<<i<<' '<<list[n][i]<<'\n';
	
	return 0;
}