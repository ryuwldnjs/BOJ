#include <iostream>
#include <vector>
#include <stack>
using namespace std;
stack<int> st;
vector<vector<int> > graph;
vector<int> sccId, discovered;
int sccCounter, vertexCounter;
int t,n,m,a,b;
int scc(int now){
	int result = discovered[now] = vertexCounter++;
	
	st.push(now);
	for(int i=0;i<graph[now].size();i++){
		int next = graph[now][i];
		
		if(discovered[next] == -1)
			result = min(result, scc(next));
		else if(sccId[next] == -1)
			result = min(result, discovered[next]);
	}
	
	
	if(result == discovered[now]){
		
		while(true){
			int tmp = st.top();
			st.pop();
			sccId[tmp] = sccCounter;
			
			if(tmp == now) break;
		}
		sccCounter++;
	}
	return result;
}

void tarjanSCC(){
	while(!st.empty()) st.pop();
	sccId.clear(), discovered.clear();
 	sccId.resize(n+1, -1), discovered.resize(n+1, -1);
	sccCounter = vertexCounter = 0; 
	for(int i=1;i<=n;i++)
		if(discovered[i]==-1) scc(i);
}
int indegree[100000+5];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>t;
	while(t--){
		cin>>n>>m;
		graph.clear();
		graph.resize(n+1);
		int cnt=0;
		for(int i=0;i<m;i++){
			cin>>a>>b;
			graph[a].push_back(b);
			
		}
		tarjanSCC();
		
		
		fill(indegree, indegree+n+1, 0);
		
		
		for(int i=1;i<=n;i++){
			
			int now = i;
			for(int j=0;j<graph[now].size();j++){
				
				int next = graph[now][j];
				
				if(sccId[now] != sccId[next])
					indegree[sccId[next]] = 1;
					
			}
		}
		
		
		for(int i=0;i<sccCounter;i++)
			if(indegree[i]==0)
				cnt++;
		cout<<cnt<<'\n';
	}
	
	return 0;
}