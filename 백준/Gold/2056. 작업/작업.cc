#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

queue<int> q;
vector<vector<int> > graph, in_time;
int time[10000+5], indegree[10000+5];
int n,t,x,y;
int main(){
	cin>>n;
	graph.resize(n+1);
	in_time.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>t>>x;
		time[i] = t; //i번 작업이 걸리는 시간 
		for(int j=0;j<x;j++){
			cin>>y;
			graph[y].push_back(i);
			indegree[i]++; //들어오는 간선 개수 추가 
		}
	}
	
	for(int i=1;i<=n;i++){
		if(indegree[i]==0)
			q.push(i);
	}
	//위상정렬 초기 설정	
	
	
	
	while(!q.empty()){
		int now = q.front();
		q.pop();
		
		if(in_time[now].size())
			time[now] += *max_element(in_time[now].begin(), in_time[now].end());
		//now로 들어오는 간선중 가장 오래 걸리는 것 
		
		for(int i=0;i<graph[now].size();i++){
			int next = graph[now][i];
			
			indegree[next]--;
			if(indegree[next]==0)
				q.push(next);
				
			in_time[next].push_back(time[now]);
		}
		
	}
	
	cout<<*max_element(time+1, time+n+1);
	return 0;
}