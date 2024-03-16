#include <iostream>
#include <algorithm>
#define INF 1e9 
using namespace std;
int n;
int dist[20][20], dp[20][1<<16];

int solve(int now, int visited){//방문할 노드, 방문한 비트필드 
	visited |= 1<<now;
	if(visited == (1<<n)-1){
		if(dist[now][0]) return dist[now][0];
		else return INF;
	}
	
	int &res = dp[now][visited];
	if(res) return res;
	res = INF;//사이드 이펙트??
	
	for(int i=1;i<n;i++){
		if(visited & (1<<i) || dist[now][i]==0) continue; 
		//이미 방문한 노드, or 시작점으로 못돌아감 
		res = min(res, solve(i, visited) + dist[now][i]);
	}
	return res; 
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>dist[i][j];
		}
	}
	
	cout<<solve(0, 0);
	return 0;
}