#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<vector<int> > adj, SCC;
stack<int> s;
int finished[2005], d[2005], SCCID[2005];
int id, n,m,a,b;

// Tarjan 알고리즘 - 강한 결합요소(SCC) 
int DFS(int now){
	d[now] = ++id;
	s.push(now);
	
	int parent = d[now];

	for(int i=0;i<adj[now].size();i++){
		int next = adj[now][i];
		
		if(d[next] == 0) parent = min(parent, DFS(next));
		else if (finished[next] == -1) parent = min(parent, d[next]);
	}	
	
	
	if(d[now] == parent){
		vector<int> scc;
		while(true){
			int t = s.top();
			s.pop();
			scc.push_back(t);
			
			//t가 속한 SCC그룹의 번호 저장 
			SCCID[t] = SCC.size();
			finished[t] = true;
			
			if(t == now) break;
		}
		SCC.push_back(scc);//SCC그룹 하나 push 
	}
	return parent;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
	while(cin>>n>>m){
		adj.clear(), SCC.clear();
		adj.resize(2*n+2);
		
		fill(finished, finished+2*n+2, -1);
		fill(d, d+2*n+2,0);
		id = 0;
		
		for(int i=0;i<m;i++){
			cin>>a>>b;
			//음수는 2n, 양수는 2n+1로 변경 
			a = a<0 ? a=-2*a : a=2*a+1;
			b = b<0 ? b=-2*b : b=2*b+1;
			// ~a -> b
			// ~b -> a
			adj[a%2?a-1:a+1].push_back(b);
			adj[b%2?b-1:b+1].push_back(a);
		}
		
		
		//SCC - 타잔알고리즘 
		for(int i=2;i<2*n+2;i++)
			if(finished[i] == -1) DFS(i);
		
		for(int i=1;i<=n;i++){
			// ~x -> x 명제가 존재할경우 모순이므로 불가능 
			if(SCCID[2*i] == SCCID[2*i+1]){
				cout<<"0\n";
				goto quit;
			}
		}
		
		
		cout<<"1\n";
		quit:;
	}
	return 0;
}