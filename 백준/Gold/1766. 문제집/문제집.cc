#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > vec;
priority_queue<int> pq;
int indegree[32000+5];

int n,m,a,b;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	vec.resize(n+1);
	for(int i=0;i<m;i++){
		cin>>a>>b;
		vec[a].push_back(b);
		indegree[b]++;
	}
	//위상정렬 그래프 구성
	
	 
	for(int i=1;i<=n;i++){
		if(indegree[i]==0) pq.push(-i);
	}//들어오는 간선이 0인것들은 힙에 저장 
	
	
	while(!pq.empty()){
		int now = -pq.top();
		pq.pop();
		cout<<now<<' ';
		for(int i=0;i<vec[now].size();i++){
			int next = vec[now][i];
			
			indegree[next]--;
			if(indegree[next]==0) pq.push(-next);
		}
	}
	return 0;
}