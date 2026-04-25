#include <iostream>
#include <queue>
using namespace std;

struct stats{
	int x, y ,dist;
};

int n,m;
int map[3005][3005];
char c;
queue<stats>  q;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

bool pass(int x, int y){
	return 0<=x&&x<n && 0<=y&&y<m;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) {
			cin>>c;
			map[i][j] = c - '0';
			if(map[i][j]==2) q.push({i,j,0});
		}
		
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int dist = q.front().dist;
		q.pop();
		if(map[x][y] > 2){
			cout<<"TAK\n"<<dist;
			return 0;
		}
		for(int i=0;i<4;i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			
			if(pass(xx, yy)){
				if(map[xx][yy] == 0){
					q.push({xx,yy,dist+1});
					map[xx][yy] = 1;
				}
				else if(map[xx][yy] > 2)
					q.push({xx,yy,dist+1});
			}

		}
		
	}
	cout<<"NIE";
	return 0;
}