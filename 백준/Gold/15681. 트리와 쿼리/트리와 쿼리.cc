#include <iostream>
#include <vector>
using namespace std;

int vertex_cnt[100000+5];
int visited[100000+5];
vector<int> vec[100000+5];

int dfs(int node){
	int cnt=1; //자기 자신도 포함 
	visited[node] = 1;
	for(int i=0;i<vec[node].size();i++){
		int next = vec[node][i];
		if(visited[next]) continue;
		
		cnt += dfs(next); //서브트리의 후손들 개수 전부 더하기 
	}
	
	return vertex_cnt[node] = cnt;
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,r,q, a,b;
	cin>>n>>r>>q;
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	//입력 끝
	
	 
	dfs(r); //루트 시작으로 서브트리의 총 노드 개수 저장 
	for(int i=0;i<q;i++){
		cin>>a;
		cout<<vertex_cnt[a]<<'\n';
	}
	return 0;
}