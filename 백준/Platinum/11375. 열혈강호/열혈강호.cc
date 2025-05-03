#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> employee(1005,-1), work(1005,-1);
//처음에는 어떤 정점도 연결되어있지 않다 
vector<int> arr[1005];
int answer;
bool visited[1005];
int n,m,x,b;

bool dfs(int a){
	if(visited[a]) return false;
	visited[a] = true;
	
	for(int i=0;i<arr[a].size();i++){
		int b = arr[a][i];
		//b가 이미 매칭되어 있으면 다시 dfs돌리기 
		if(work[b] == -1 || dfs(work[b])){
			//증가 경로 발견할경우.. 
			work[b] = a;
			employee[a] = b;
			return true;
		}
	}
	return false;
}
int main(){
	cin>>n>>m;
	for(int a=1;a<=n;a++){
		cin>>x;
		for(int i=0;i<x;i++){
			cin>>b;
			arr[a].push_back(b);
			//직원a는 b작업을 할  수있다!! 
		}
	}
	
	for(int i=1;i<=n;i++){
		fill(visited, visited+n+1, false);
		if(dfs(i)) answer++;
	}
	cout<<answer;
	return 0;
}