#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> tree;
queue<int> q;
int dist[100000+5];
int n,k,a,b,tmp;
int main(){
	cin>>n>>k;
	tree.resize(n);
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		tree[a].push_back(b);
	}
	
	q.push(0);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		
		for(int i=0;i<tree[now].size(); i++){
			int next = tree[now][i];
			dist[next] = dist[now] + 1;
			q.push(next);
		}
	}
	
	for(int i=0;i<n;i++){
		cin>>tmp;
		if(tmp == k){ // 가중치를 찾았다! 
			cout<<dist[i];
		}
	}
	return 0;
}