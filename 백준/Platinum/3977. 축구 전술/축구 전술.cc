#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<vector<int> > adj;
vector<vector<int> > SCC;

int id,d[100001];
int finished[100001], SCCID[100001];
stack<int> s;
int t,n,m,a,b;

int DFS(int now){
	d[now] = ++id;
	s.push(now);
	
	int parent = d[now];
	for(int i=0;i<adj[now].size();i++){
		int next = adj[now][i];
		
		if(d[next]==0) parent = min(parent, DFS(next));
		else if(finished[next]==-1) parent = min(parent, d[next]);
	}
	
	if(d[now] == parent){
		vector<int> scc;
		while(true){
			int t =s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			SCCID[t] = SCC.size();
			if(t == now) break;
		}
		SCC.push_back(scc);
	}
	return parent;
}


int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		adj.clear(), SCC.clear();
		s = stack<int>();
		cin>>n>>m;
		fill(finished, finished+n,-1), fill(d, d+n,0);
		id=0;
		adj.resize(n);
		int indegree[100001]={};
		int cnt=0, ans;
		bool NoAnswer = false;
		
		for(int i=0;i<m;i++){
			cin>>a>>b;
			adj[a].push_back(b);
		}
		
		for(int i=0;i<n;i++)
			if(finished[i]==-1) DFS(i);
		//여기까지 타잔알고리즘
		
		
		 
		//위상정렬 처리 
		for(int i=0;i<adj.size();i++){
			for(int j=0;j<adj[i].size();j++){
				int next = adj[i][j];
				
				if(SCCID[i] != SCCID[next])
					indegree[SCCID[next]]++;
			}
		}
		
		//indegree가 0인 경우를 찾고, 두개이상일경우 노답 
		for(int i=0;i<SCC.size();i++){
			if(indegree[i]==0){
				cnt++;
				ans = i;
				if(cnt>1) NoAnswer = true;
			}
		}
		
		
		//답 출력 
		if(NoAnswer) cout<<"Confused\n";
		else{
			sort(SCC[ans].begin(), SCC[ans].end());
			for(int i=0;i<SCC[ans].size();i++)
				cout<<SCC[ans][i]<<'\n';
		}
		cout<<'\n';
		
		
	}
	return 0;
}