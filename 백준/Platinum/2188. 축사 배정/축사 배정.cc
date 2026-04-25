#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > wish;
vector<int> cage;
bool visited[205];
int n,m,x,y,answer;
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
	cin>>n>>m;
	wish.resize(n+1);// wish[i] : i번째 소가 들어가길 원하는 축사 번호들 
	cage.resize(m+1, -1); //cage[i] : i번째 축사에 할당된 소 번호 
	for(int i=1;i<=n;i++){
		cin>>x;
		while(x--){
			cin>>y;
			wish[i].push_back(y);
		}
	}
	
	for(int i=1;i<=n;i++){
		fill(visited, visited+n+1, false);
		if(DFS(i)) answer++;
	}
	cout<<answer;
	
	return 0;
}