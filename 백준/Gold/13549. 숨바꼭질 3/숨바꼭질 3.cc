#include <iostream>
#include <vector>
#include <queue>
#define INF 1234567890
#define pii pair<int,int>; //아니 이거 왜 안됨????!!?!?!?!? 
using namespace std;

vector<vector<pair<int,int>>> a(100000+1);
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int dist[100000+5];

bool pass(int x){
	if(0<=x&&x<=100000) return true;
	return false;
}

void dijkstra(int start){
	for(int i=0;i<=100000;i++) dist[i] = INF;
	
	
	dist[start] = 0;
	pq.push({dist[start], start});
	
	while(!pq.empty()){
	//	printf("z");
		int d = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		
		if(dist[now] < d) continue; //이미 더 짧은 경로가 있을때 
		
		
		for(int i=0;i<a[now].size(); i++){
			int next = a[now][i].first;
			int next_d = d + a[now][i].second;
			
			if(next_d < dist[next]){ //거리 갱신 
				dist[next] = next_d;
				pq.push({next_d, next});
			}
		}
		
	}
	
}

int n,k;
int main(){
	cin>>n>>k;
	
	//간선 연결 
	for(int i=0;i<=100000;i++){
		if(pass(i-1)) a[i].push_back({i-1, 1});
		if(pass(i+1)) a[i].push_back({i+1, 1});
		if(pass(i*2)) a[i].push_back({i*2, 0});
	}
	
	dijkstra(n);
	
	cout<<dist[k]; 
	return 0;
} 