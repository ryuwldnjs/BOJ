#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > arr;
vector<int> indegree;

queue<int> q;
int n,m,a,b;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	arr.resize(n+1), indegree.resize(n+1);
	
	for(int i=0;i<m;i++){
		cin>>a>>b;
		arr[a].push_back(b);
		indegree[b]++;//b로 들어오는 간선 하나 증가
		 
	}
	for(int i=1;i<=n;i++){
		if(indegree[i]==0) q.push(i);//들어오는 간선이 없는 정점 push 
	}
	
	while(!q.empty()){
		int now = q.front();
		q.pop();
		cout<<now<<' ';
		for(int i=0;i<arr[now].size();i++){
			int next = arr[now][i];
			
			indegree[next]--;
			if(indegree[next]==0) q.push(next);
		}
	}
	return 0;
}