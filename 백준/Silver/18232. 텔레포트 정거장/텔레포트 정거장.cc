#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii=pair<int,int>;
int n,m,s,e;
queue<pii> q;
vector<vector<int>> graph(300000+5);
vector<bool> visited(300000+5);
bool pass(int x){
	return 1<=x&&x<=n && !visited[x];
}

int main(){
	cin>>n>>m;
	cin>>s>>e;
	for(int i=0;i<m;i++){
		int x,y; cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	q.push({s,0});
	while(!q.empty()){
		int now = q.front().first;
		int dist = q.front().second;
		q.pop();
		if(now == e){
			cout<<dist;
			return 0;
		}
		
		if(pass(now-1)){
			q.push({now-1, dist+1});
			visited[now-1] = true;
		}
		if(pass(now+1)){
			q.push({now+1, dist+1});
			visited[now+1] = true;
		}
		for(int i=0;i<graph[now].size();i++){
			int next = graph[now][i];
			if(pass(next)){
				q.push({next, dist+1});
				visited[next] = true;
			}
		}
	}
	return 0;
}