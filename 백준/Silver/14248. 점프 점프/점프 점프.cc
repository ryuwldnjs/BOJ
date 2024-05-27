#include <iostream>
using namespace std;
int n,s,map[100000+5];
bool visited[100000+5];
bool pass(int idx){
	return 0<=idx&&idx<n && !visited[idx];
}
int dfs(int now){
	visited[now] = true;
	int cnt = 1;
	
	if(pass(now - map[now])) cnt += dfs(now - map[now]);
	if(pass(now + map[now])) cnt += dfs(now + map[now]);
	return cnt;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>map[i];
	}
	cin>>s;
	cout<<dfs(s-1);
	return 0;
}