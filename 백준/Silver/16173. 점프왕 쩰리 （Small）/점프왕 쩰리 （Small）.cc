#include <iostream>
#include <queue>
using namespace std;
using pii=pair<int,int>;
int n,map[5][5];
queue<pii> q;
bool visited[5][5];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	
	q.push({0,0});
	visited[0][0] = true;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		int dist = map[x][y];
		q.pop();
		
		if(x == n-1 && y == n-1){
			cout<<"HaruHaru";
			return 0;
		}
		
		if(x+dist < n && !visited[x + dist][y]){
			q.push({x+dist, y});
			visited[x+dist][y] = true;
		}
		if(y+dist < n && !visited[x][y + dist]){
			q.push({x, y+dist});
			visited[x][y+dist] = true;
		}
		
	}
	cout<<"Hing";
	return 0;
}