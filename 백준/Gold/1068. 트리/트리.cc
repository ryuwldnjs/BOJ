#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
bool visited[55];
int parent[55];
int n,root,target,leaf;

void dfs(int now){
	visited[now] = true;
	if(tree[now].empty()) leaf++;
	
	for(int i=0;i<tree[now].size(); i++){
		int next = tree[now][i];
		if(!visited[next]) dfs(next);
	}
}
int main(){
	cin>>n;
	tree.resize(n);
	for(int i=0;i<n;i++){
		cin>>parent[i];
		if(parent[i] == -1) {
			root = i;
			continue;
		}
		tree[parent[i]].push_back(i);
	}
	cin>>target;
	if(parent[target] == -1){
		cout<<0;
		return 0;
	}
	vector<int> &tmp = tree[parent[target]];
	for(int i=0;i<tmp.size();i++){
		if(tmp[i] == target){
			tmp.erase(tmp.begin()+i);
			break;
		}
	}
	
	
	dfs(root);
	
	cout<<leaf;
	
	return 0;
}