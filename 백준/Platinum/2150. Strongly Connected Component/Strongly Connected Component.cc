#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int> > adj;//그래프 
vector<vector<int> > SCC;// 각SCC별 노드들 모음
stack<int> s;
int id, d[10001];
int finished[10001];
int V,E,a,b;

bool cmp(vector<int> &a, vector<int> &b){
	return a.front() < b.front();
}

//타잔 알고리즘 - 강결합요소 
int DFS(int now){
	d[now] = ++id;
	s.push(now);
	int parent = d[now];
	for(int i=0;i<adj[now].size();i++){
		int next = adj[now][i];
		if(d[next]==0) parent = min(parent, DFS(next));
		else if(finished[next]==-1) parent = min(parent, d[next]);
		
	}
	if(parent == d[now]){
		vector<int> scc;
		while(true){
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if(t == now) break;
		}
		SCC.push_back(scc);
	}
	return parent;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>V>>E;
	adj.resize(V+1);
	fill(finished, finished+V+1,-1);
	
	for(int i=0;i<E;i++){
		cin>>a>>b;
		adj[a].push_back(b);
	}
	
	for(int i=1;i<=V;i++){
		if(finished[i]==-1) DFS(i);
	}
	
	//각 SCC집합들을 정렬한 후
	//가장 작은정점 번호 순으로 다시 정렬 
	for(int i=0;i<SCC.size();i++) sort(SCC[i].begin(), SCC[i].end());
	sort(SCC.begin(), SCC.end(), cmp);


	cout<<SCC.size()<<'\n';
	for(int i=0;i<SCC.size();i++){
		for(int j=0;j<SCC[i].size();j++){
			cout<<SCC[i][j]<<' ';
		}
		cout<<"-1\n";
	}
	return 0;
}