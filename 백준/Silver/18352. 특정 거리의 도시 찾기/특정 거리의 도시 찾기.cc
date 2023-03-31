#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> map;
queue<int> q;
int visited[300000+10], dist[300000+10];
int n,m,k,x,a,b,cnt;
int main(){
	cin>>n>>m>>k>>x;
	map.resize(n+1);
	for(int i=0;i<m;i++){
		cin>>a>>b;
		map[a].push_back(b);
	}
	
	q.push(x);
	visited[x] = 1;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		
		for(int i=0;i<map[now].size(); i++){
			int next = map[now][i];
			
			if(!visited[next]){
				q.push(next);
				visited[next] = 1;
				dist[next] = dist[now] + 1;
			}
		}
	}
	bool flag = false;
	for(int i=1;i<=n;i++){
		if(dist[i] == k){
			cout<<i<<'\n';
			flag = true;
		}
	}
	if(!flag) cout<<-1;
	return 0;
}