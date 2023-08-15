#include <iostream>
#include <vector>
#define INF 5000000
using namespace std;
using pii=pair<int,int>;
vector<vector<pii>> graph;
int dist[500+5];
int t,n,m,w,a,b,c;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n>>m>>w;
		graph = vector<vector<pii>>(n+1);
		bool NoAnswer = false;
		fill(dist, dist+n+1, INF);
		dist[1] = 0;
		
		for(int i=0;i<m;i++){
			cin>>a>>b>>c;
			graph[a].push_back({b,c});
			graph[b].push_back({a,c});
		}
		
		for(int i=0;i<w;i++){
			cin>>a>>b>>c;
			graph[a].push_back({b,-c});
		}
		
		for(int it=0;it<n;it++){
			for(int i=1;i<=n;i++){
				for(int j=0;j<graph[i].size();j++){
					int next = graph[i][j].first;
					int next_dist = graph[i][j].second;
					if(dist[next] > dist[i] + next_dist){
						dist[next] = dist[i] + next_dist;
						if(it == n-1) NoAnswer = true;
					}
				}
			}
			
		}
		
		
		if(NoAnswer == true) cout<<"YES\n";
		else cout<<"NO\n";
		
	}
	return 0;
}