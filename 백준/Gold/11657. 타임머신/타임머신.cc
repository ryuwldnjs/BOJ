#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<pair<int,int> > > adj;
long long dist[505];
const long long INF = 1e18;
int n,m,a,b,c;
bool NoAnswer;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	adj.resize(n+1);
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
	}
	//초기에는 모든 정점에 대해 거리 무한대 설정 
	fill(dist, dist+n+1, INF);
	dist[1] = 0; //출발점
	
	//벨만_포드 알고리즘 - 음의 가중치가 존재하는 그래프 
	//n-1 + 1번 반복 
	//마지막까지도 거리 갱신이 이루어진다?? -> 음의 사이클 존재 
	for(int i=0;i<n;i++)
		for(int j=1;j<=n;j++){
			for(int k=0;k<adj[j].size();k++){
				int next = adj[j][k].first;
				int d = adj[j][k].second;
				if(dist[j] != INF && dist[next] > dist[j] + d){
					dist[next] = dist[j] + d;
					if(i==n-1) NoAnswer = true;//음의 사이클 존재 
				}
			}
		}
		
	if(NoAnswer) cout<<-1;
	else
		for(int i=2;i<=n;i++){
			if(dist[i]==INF) cout<<"-1\n";
			else cout<<dist[i]<<'\n';
		}
	return 0;
}