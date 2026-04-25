#include <iostream>
#include <vector>
using namespace std;
vector<int> vec;
int n,m;
void dfs(int level){
	if(level==m){
		for(int i=0;i<vec.size();i++) cout<<vec[i]<<' ';
		cout<<'\n';
		return;
	}
	
	for(int i=1;i<=n;i++){
		vec.push_back(i);
		dfs(level+1);
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