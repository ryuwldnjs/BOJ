#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int id, d[20005];
int finished[20005], SCCID[20005];
stack<int> s;
vector<vector<int> > adj, SCC;
int n,m,a,b;

//Tarjan알고리즘 - SCC
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
			int tmp = s.top();
			s.pop();
			scc.push_back(tmp);
			finished[tmp] = true;
			SCCID[tmp] = SCC.size();//tmp가 속한 SCC의번호 저장 
			if(tmp == now) break;			
		}
		SCC.push_back(scc);
	}
	return parent;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	adj.resize(2*n+2);
	fill(finished, finished+2*n+2, -1);
	
	while(m--){
		cin>>a>>b;
		//음수(NOT게이트 ~)면 2n, 양수면 2n+1 
		a = a<0 ? -2*a : 2*a+1;
		b = b<0 ? -2*b : 2*b+1;
		adj[a%2?a-1:a+1].push_back(b);
		adj[b%2?b-1:b+1].push_back(a);
		// ~a -> b
		// ~b -> a를 표현 한 것임. 
	}

	//노드 번호는 2부터 시작함 
	for(int i=2;i<=2*n+1 ;i++)
		if(finished[i]==-1) DFS(i);
		
	//2-SAT 답 존재 유무 확인 
	for(int i=1;i<=n;i++){
		if(SCCID[2*i] == SCCID[2*i+1]){
			cout<<0;
			return 0;
		}
	}

	//2-sat 명제를 만족시키는 변수들  결정  
	pair<int,int> p[20005];
	for(int i=2;i<2*n+2;i++)
		p[i] = {SCCID[i], i};
	sort(p+2 , p+2*n+2);
	
	int answer[10005];
	fill(answer, answer+n+1, -1);
	for(int i=2*n+1;i>=2;i--){
		int t = p[i].second;
		if(answer[t/2] == -1) answer[t/2] = (t%2)^1;
	}
		
	cout<<"1\n";
	for(int i=1;i<=n;i++) cout<<answer[i]<<' ';
	return 0;
}