#include <iostream>
#include <vector>
using namespace std;
int visited[10];
vector<int> vec;
int n,m;
void dfs(int level){
	if(level==m){
		for(int i=0;i<vec.size();i++) cout<<vec[i]<<' ';
		cout<<'\n';
	}
	
	for(int i=1;i<=n;i++){
		if(visited[i]) continue;
		visited[i] = 1;
		vec.push_back(i);
		dfs(level+1);
		visited[i] = 0;
		vec.pop_back();
	}
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	
	dfs(0);
	return 0;
}