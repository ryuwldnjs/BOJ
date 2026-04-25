#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1234567890
using namespace std;



int c[2005][2005], f[2005][2005], parent[2005];
int totalFlow;

vector<int> arr[2005];

int n,m,k,x,b;

void networkFlow(int source, int sink){
	while(true){
		fill(parent, parent+n+m+4, -1);
		queue<int> q;
		q.push(source);
		
		while(!q.empty()){
			int now = q.front();
			q.pop();
			
			for(int i=0;i<arr[now].size();i++){
				int next = arr[now][i];
				
				if(c[now][next] - f[now][next] > 0 && parent[next] == -1){
					q.push(next);
					parent[next] = now;
				}
			}
		}
		
		
		if(parent[sink] == -1) break;
		int amount = INF;
		for(int i=sink; i!=source; i=parent[i])
			amount = min(amount, c[parent[i]][i] - f[parent[i]][i]);
			
		for(int i=sink; i!=source; i=parent[i]){
			f[parent[i]][i] += amount;
			f[i][parent[i]] -= amount;
		}
		totalFlow += amount;
	}
} 

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>m>>k;
	for(int a=1;a<=n;a++){
		cin>>x;
		for(int i=0;i<x;i++){
			cin>>b;
			arr[a].push_back(b+n);
			arr[b+n].push_back(a);
			c[a][b+n] = 1;
			
		}
		 
	}
	
	// 0, n+m+1, n+m+2이 source, n+m+3이 sink
	
	//각 사람들한테 1씩 흘려주고, 모든 벌점은 1번 사람한테 전부 흘려준다.
	//그다음, 1번사람이 적절히 다음사람에게 마저 흘려준다.
	//다음사람이 그 다음사람에게..이렇게 반복
	 
	for(int i=1;i<=n;i++){
		arr[0].push_back(i);
		arr[i].push_back(0);
		c[0][i] = 1;
		
		arr[n+m+2].push_back(i);
		arr[i].push_back(n+m+2);
		c[n+m+2][i] = INF;
	}
	
	arr[n+m+1].push_back(n+m+2);
	arr[n+m+2].push_back(n+m+1);
	c[n+m+1][n+m+2] = k;
	
	
	for(int i=1;i<=m;i++) {
		arr[i+n].push_back(n+m+3);
		arr[n+m+3].push_back(i+n);
		c[i+n][n+m+3] = 1;
	}
	
	
	networkFlow(0, n+m+3);
	networkFlow(n+m+1, n+m+3);
	cout<<totalFlow;
	return 0;
} 