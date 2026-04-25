#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > vec, dag;
int visited[1000000+5];
int dp[1000000+5][2];
int n, a,b;
/*
int dfs(int node, int early){
//	int flag=0;
//	visited[node] = 1;
	
	if(dp[node][early]) return dp[node][early]; 
	dp[node][early]= early;//자기자신 추가 
	
	for(int i=0;i<dag[node].size();i++){
		int next = dag[node][i];
		//if(visited[node]) continue;
		//flag=1;
		
		if(early==0)
			dp[node][0] += dfs(next, 1);
		else
			dp[node][1] += min(dfs(next, 0), dfs(next, 1)); 
	}
	//if(flag==0) 
	
	
	return dp[node][early];
}*/

void dfs(int node){
//	int flag=0;
	visited[node] = 1;
	
//	if(dp[node][early]!=-1) return dp[node][early]; 
	dp[node][1]= 1;//자기자신 추가 
	
	for(int i=0;i<vec[node].size();i++){
		int next = vec[node][i];
		if(visited[next]) continue;
		//flag=1;
		
		dfs(next);
		dp[node][0] += dp[next][1];
		
		dp[node][1] += min(dp[next][0], dp[next][1]); 
	}
	//if(flag==0) 
	
	
	//return dp[node][early];
}


void mk_dag(int node){
	visited[node] = 1;
	for(int i=0;i<vec[node].size();i++){
		int next = vec[node][i];
		if(visited[next]) continue;
		dag[node].push_back(next);
		mk_dag(next);
	}
}
int main(){
	cin>>n;
	vec.resize(n+1);
	dag.resize(n+1);
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
//	mk_dag(1); //DAG 생성 
//	for(int i=0;i<=n;i++) dp[i][0] = dp[i][1] = -1;
//	int off = dfs(1); //루트가 얼리어댑터가 아닐때 
//	fill(visited, visited+n+2, 0);
//	for(int i=0;i<=n+1;i++) dp[i][0] = dp[i][1] = 0;
	dfs(1);	
	int off = dp[1][0];
	int on = dp[1][1]; //루트가 얼리 어댑터 일때 
//	printf("%d %d", off, on);
	
	cout<<min(on, off);
	return 0;
}