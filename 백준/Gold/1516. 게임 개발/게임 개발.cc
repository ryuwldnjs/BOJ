#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > vec, in;
queue<int> q;
int n, w[505], x, indegree[505], answer;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n;
	vec.resize(n+1), in.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>w[i];
		while(1){
			cin>>x;
			if(x==-1) break;
			vec[x].push_back(i);
			indegree[i]++;
		}
	}
	//위상정렬을 위한 그래프 구성
	 
	
	for(int i=1;i<=n;i++)
		if(indegree[i]==0) q.push(i);
	//들어오는 간선이 없는 정점부터 시작
	
	 
	while(!q.empty()){
		int now = q.front();
		q.pop();
		
		int MAX = 0;
		for(int i=0;i<in[now].size();i++){
			MAX = max(MAX, in[now][i]);
		}
		w[now] += MAX;
		//들어오는 가중치중 가장 큰 것을 더해줌 
		
		
		for(int i=0;i<vec[now].size();i++){
			int next = vec[now][i];
			in[next].push_back(w[now]);//next로 들어가는 가중치 원소를 하나 넣어줌 
			
			indegree[next]--;
			if(indegree[next]==0) q.push(next);
		}
	}
	
	for(int i=1;i<=n;i++) cout<<w[i]<<'\n';
	return 0;
}