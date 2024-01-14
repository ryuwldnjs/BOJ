#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int> > vec[100000+5];
vector<int> route; // 두 로봇사이의 경로 저장 
int visited[100000+5];
pair<int,int> pre[100000+5]; //경로 역추적 

int n,a, b;
int from, to, cost;
int sum, MAX = -1;

void dfs(int a){
	if(visited[a]) return;
	visited[a] = 1; //방문 
	if(a == b){
		return;
	}
	for(int i=0;i<vec[a].size();i++){
		int next = vec[a][i].first;
		if(visited[next]) continue;
		pre[next] = {a, i};
		dfs(next);
	}
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin>>n>>a>>b;
	for(int i=0;i<n-1;i++){
		cin>>from>>to>>cost;
		vec[from].push_back({to, cost});
		vec[to].push_back({from, cost});
		//양방향 
	}
	dfs(a); // a에서b로 가는 경로 찾기 
	
	
	if(a==b){
		cout<<0; //같은 곳에 로봇이 있을때 어우; 
		return 0;
	}
	
	int now = b;
	int select; //어떤 간선이었는지 
	while(now!=a){ //역 추적 
		pair<int,int> tmp = pre[now];
		now = tmp.first;
		select = tmp.second;
		route.push_back(vec[now][select].second); //간선 길이 저장 
	}
	
	for(int i=0;i<route.size();i++){
		sum += route[i];
		MAX = max(MAX, route[i]);
	}
	int answer = sum - MAX; //가장 큰 간선만 제외 
	cout<<answer;
	return 0;
} 