#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[500005];
int answer, visited[500005];
int n,a,b;
void dfs(int node, int level){
	int son=0;
	visited[node] = 1;
	for(int i=0;i<tree[node].size();i++){
		int next = tree[node][i];
		if(!visited[next]){
			dfs(next, level+1);
			son++;
		}
	}
	if(son==0) answer+=level;
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	dfs(1, 0);
	
	if(answer%2==1) cout<<"Yes";
	else cout<<"No";
	return 0;
}