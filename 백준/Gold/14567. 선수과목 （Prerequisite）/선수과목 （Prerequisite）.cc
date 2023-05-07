#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> arr;
vector<int> indegree;
vector<int> level;
queue<int> q;
int n,m,a,b;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	
	arr.resize(n+1);
	indegree.resize(n+1);
	level.resize(n+1);
	for(int i=0;i<m;i++){
		cin>>a>>b;
		arr[a].push_back(b);
		indegree[b]++;
	}
	
	for(int i=1;i<=n;i++){
		if(indegree[i] == 0){
			q.push(i);
			level[i] = 1;
		}
	}
	
	while(!q.empty()){
		int now = q.front();
		q.pop();
		
		for(int i=0;i<arr[now].size(); i++){
			int next = arr[now][i];
			
			if(--indegree[next] == 0){
				q.push(next);
				level[next] = level[now] + 1;
			}
		}
		
		
	}
	
	for(int i=1;i<=n;i++){
		cout<<level[i]<<' ';
	}
	return 0;
}