#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define INF 1000000000
using namespace std;
using pii = pair<int,int>;
/*
struct stats{
	int cost;
	int des;
	int pre;
	
};
struct cmp{
	bool operator() (const stats &a, const stats &b){
		return a.cost > b.cost;
	}
};*/

stack<int> path;
vector<vector<pii>> v;
priority_queue<pii, vector<pii>, greater<pii>> pq;
int dist[1005];
int pre[1005];

int n, m, a,b,c;
void dijkstra(int start){
	for(int i=0;i<1005;i++) dist[i] = INF;
	
	dist[start] = 0;
	pq.push({dist[start], start});
//	pre[start] = -1;
	while(!pq.empty()){
		int d = pq.top().first;
		int now = pq.top().second;
	//	int front = pq.top().pre;
	//	printf("%d\n", now);
		pq.pop();
		
		if(dist[now] < d) continue;
		//pre[now] = front;
		for(int i=0;i<v[now].size(); i++){
			int next = v[now][i].first;
			int next_d =  v[now][i].second + d;
			
			if(next_d < dist[next]){
				dist[next] = next_d;
				pq.push({next_d, next});
				pre[next] = now; //경로 기록 
			}
		}
		
		
	}
	
}
int main() {
	cin>>n>>m;
	v.resize(n+1);
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		v[a].push_back({b, c});
	}
	
	cin>>a>>b;
	
	dijkstra(a);
//	printf("Zz");
	for(int now = b; now != a; now = pre[now])
		path.push(now);
	path.push(a);
//	for(int i=1;i<10;i++) printf("%d, ", pre[i]);
	cout<<dist[b]<<'\n'<<path.size()<<'\n';
	while(!path.empty()){
		cout<<path.top()<<' ';
		path.pop();
	}
	return 0;
}