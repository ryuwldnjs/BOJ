#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec;
int n,m, number[10];
void dfs(int level){
	if(level==m){
		for(int i=0;i<vec.size();i++) cout<<vec[i]<<' ';
		cout<<'\n';
		return;
	}
	int tmp=-1;
	for(int i=0;i<n;i++){
		if(number[i]==tmp) continue;
		
		tmp = number[i];
		vec.push_back(number[i]);
		dfs(level+1);
		vec.pop_back();
	}
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>number[i];
	sort(number, number+n);
	dfs(0);
	return 0;
}