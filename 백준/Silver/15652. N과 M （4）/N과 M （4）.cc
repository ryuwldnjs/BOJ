#include <iostream>
#include <vector>
using namespace std;
vector<int> vec;
int n,m;
void dfs(int level, int prev){
	if(level==m){
		for(int i=0;i<vec.size();i++) cout<<vec[i]<<' ';
		cout<<'\n';
		return;
	}
	
	for(int i=prev;i<=n;i++){
		vec.push_back(i);
		dfs(level+1, i);
		vec.pop_back();
	}
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	dfs(0, 1);
	return 0;
}