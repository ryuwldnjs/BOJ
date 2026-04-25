#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> st;
vector<vector<int> > adj;
vector<int> sccId, discovered;

int n, m,a,b, vertexCounter, sccCounter;
int indegree[100000+5], cnt;
int scc(int now){
	
	int result = discovered[now] = vertexCounter++;
	
	st.push(now);
	for(int i=0;i<adj[now].size();i++){
		int next = adj[now][i];
		
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
	sccId.resize(n, -1), discovered.resize(n, -1);
	
	for(int i=0;i<n;i++){
		if(discovered[i] == -1) scc(i);
	}
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	adj.resize(n);
	for(int i=0;i<m;i++){
		cin>>a>>b;
		adj[a].push_back(b);
	}
	
	
		
	tarjanSCC();
 
		
	//위상정렬 - indegree 설정 
	for(int i=0;i<n;i++){
		for(int j=0;j<adj[i].size();j++){
			int next = adj[i][j];
			
			if(sccId[i] != sccId[next])
				indegree[sccId[next]]++;
		}
	}
	
	for(int i=0;i<sccCounter;i++)
		if(indegree[i] == 0) cnt++;
		
	cout<<cnt;
	return 0;
}