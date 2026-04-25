#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> st;
vector<vector<int> > adj, SCCset;
vector<int> sccId, discovered;

int n, cost[105],x, vertexCounter, sccCounter;
int answer;
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
			SCCset[sccCounter].push_back(tmp);
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
	scanf("%d", &n);
	adj.resize(n), SCCset.resize(n);
	for(int i=0;i<n;i++) scanf("%d", &cost[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%1d",&x);
			if(x) adj[i].push_back(j);
		}
	}
	
	
	tarjanSCC();
	for(int i=0;i<sccCounter;i++){
		int MIN = 1234567890;
		for(int j=0;j<SCCset[i].size();j++){
			MIN = min(MIN, cost[SCCset[i][j]]);
		}
		answer += MIN;
	}
	printf("%d", answer);
	return 0;
}