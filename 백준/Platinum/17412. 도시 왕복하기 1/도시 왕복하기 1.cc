#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1234567890
 
using namespace std;
vector<int> arr[405];

//용량과 유량(반대경우 음수) 
int n,p,a,b;
int c[405][405], f[405][405], parent[405];
int totalFlow;
//에드몬드_카프 알고리즘 - 최대유량   
void networkFlow(int source, int sink){
	while(true){
		fill(parent, parent+n+1, -1);
		queue<int> q;
		q.push(source);
		
		while(!q.empty()){
			int now = q.front();
			q.pop();
			
			for(int i=0;i<arr[now].size();i++){
				int next = arr[now][i];
				//잔여 용량이 남은 간선을 따라 탐색 
				if(c[now][next] - f[now][next] > 0 && parent[next] == -1){
					q.push(next);
					parent[next] = now;
				}
			}
					
		}
	
		if(parent[sink] == -1) break;
		int amount = INF;
		for(int i=sink; i!=source; i = parent[i])
			amount = min(amount, c[parent[i]][i] - f[parent[i]][i]);
		
		for(int i=sink; i!=source; i=parent[i]){
			f[parent[i]][i] += amount;
			f[i][parent[i]] -= amount;
		}
		totalFlow += amount;
	}
}

int main(){
	cin>>n>>p;
	for(int i=0;i<p;i++){
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
		c[a][b] = 1;
	}
	//source는 1, sink는2인 그래프 탐색 시작 
	networkFlow(1, 2);
	cout<<totalFlow;
	return 0;
}