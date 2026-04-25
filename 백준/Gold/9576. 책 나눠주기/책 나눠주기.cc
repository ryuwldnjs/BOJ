#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > wish;
vector<int> cage;
bool visited[1005];
int n,m,x,y,answer,t,a,b;
bool DFS(int x){
	if(visited[x]) return false;
	visited[x] = true;
	
	for(int i=0;i<wish[x].size();i++){
		int y = wish[x][i];
		
		if(cage[y] == -1 || DFS(cage[y])){
			cage[y] = x;
			return true;
		}
	}
	return false;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		
		cin>>n>>m;
	wish.clear(), wish.resize(m+1);// wish[i] : i번째 소가 들어가길 원하는 축사 번호들 
	cage.clear(), cage.resize(n+1, -1); //cage[i] : i번째 축사에 할당된 소 번호 
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		for(int k=a;k<=b;k++){
			wish[i].push_back(k);
		}
	}
	
	for(int i=1;i<=m;i++){
		fill(visited, visited+m+1, false);
		if(DFS(i)) answer++;
	}
	cout<<answer<<'\n';
	answer=0;
	}
	
	
	return 0;
}