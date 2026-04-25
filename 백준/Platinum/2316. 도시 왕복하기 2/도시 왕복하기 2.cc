#include <iostream>
#include <vector>
#include <queue>
#define INF 1234567890
using namespace std;
vector<int> arr[810];
int c[810][810], f[810][810], parent[810]; 
int totalFlow;

int n,p,a,b;

//에드몬드카프 
void networkFlow(int source, int sink){
	while(true){
		fill(parent, parent+2*n+2, -1);
		queue<int> q;
		q.push(source);
		parent[source] = source;
		
		while(!q.empty()){
			int now = q.front();
			q.pop();
			
			for(int i=0;i<arr[now].size();i++){
				int next = arr[now][i];
				
				if(c[now][next] - f[now][next] > 0 &&parent[next] == -1){
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
	
	cin>>n>>p;
	for(int i=0;i<p;i++){
		cin>>a>>b;
		arr[2*a].push_back(2*b-1);//들어오는곳, 나가는 곳을 분리하여 생각 
		arr[2*b-1].push_back(2*a);
		
		arr[2*b].push_back(2*a-1);
		arr[2*a-1].push_back(2*b);
		c[2*a][2*b-1] = 1;
		c[2*b][2*a-1] = 1;
	}
	
	//in out 연결 
	for(int i=3;i<=n;i++){
		arr[2*i-1].push_back(2*i);
		arr[2*i].push_back(2*i-1);
		c[2*i-1][2*i] = 1;
	}
	arr[1].push_back(2);
	arr[2].push_back(1);
	arr[3].push_back(4);
	arr[4].push_back(3);
	c[1][2] = c[3][4] = INF;
	
	
	networkFlow(2, 3);
	cout<<totalFlow;
	return 0;
}