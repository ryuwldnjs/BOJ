#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int visited[10], number[10];
vector<int> vec;
int n,m;
void dfs(int level, int prev){
	if(level==m){
		for(int i=0;i<vec.size();i++) cout<<vec[i]<<' ';
		cout<<'\n';
	}
	int tmp=-1;
	for(int i=prev;i<n;i++){
		if(visited[i] || number[i]==tmp) continue;

		tmp = number[i];
		vec.push_back(number[i]);
		
		visited[i] = 1;
		dfs(level+1, i);
		visited[i] = 0;
		
		vec.pop_back();
	}
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>number[i];
	sort(number, number+n);
	
	dfs(0, 0);
	return 0;
}