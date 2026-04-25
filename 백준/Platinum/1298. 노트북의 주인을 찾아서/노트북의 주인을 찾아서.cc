#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > arr;
vector<int> laptop;
bool visited[105];
int n,m,a,b;
int answer;

//이분 매칭 
bool DFS(int a){
	if(visited[a]) return false;
	visited[a] = true;
	
	for(int i=0;i<arr[a].size();i++){
		int b = arr[a][i];
		
		if(laptop[b] == -1 || DFS(laptop[b])){
			laptop[b] = a;
			return true;
		}
	}
	return false;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	arr.resize(n+1), laptop.resize(n+1, -1);
	
	for(int i=0;i<m;i++){
		cin>>a>>b;
		arr[a].push_back(b);
	}
	
	for(int i=1;i<=n;i++){
		fill(visited, visited+n+1, false);
		if(DFS(i)) answer++;
	}
	cout<<answer;
	return 0;
}