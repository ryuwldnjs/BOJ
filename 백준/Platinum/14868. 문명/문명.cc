#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii=pair<int,int>;
vector<vector<pii>> parent(2005, vector<pii>(2005, {-2,-2}));
vector<vector<bool>> visited(2005, vector<bool>(2005));
int n,k;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<pii> q;

pii find(pii a){
	if(parent[a.first][a.second] == make_pair(-1,-1) || parent[a.first][a.second] == make_pair(-2,-2)) 
		return a;
	return parent[a.first][a.second] = find(parent[a.first][a.second]);
}

int merge(pii a, pii b){
	a = find(a);
	b = find(b);
	
	if(a == b) return 0;
	if(parent[a.first][a.second] == make_pair(-2,-2)){
		parent[a.first][a.second] = b;
		return 0; 
	}
	else if(parent[b.first][b.second] == make_pair(-2,-2)){
		parent[b.first][b.second] = a;
		return 0; 
	}
	//문명끼리 통합된 경우 
	parent[b.first][b.second] = a;
	return 1;
}
bool pass(int x, int y){
	return 0<x&&x<=n && 0<y&&y<=n;
}


int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>k;
	int civilization = k;
	int x,y;
	for(int i=0;i<k;i++){
		cin>>x>>y;
		q.push({x,y});
		parent[x][y] = {-1,-1}; //문명 표시 
		visited[x][y] = true;
		for(int j=0;j<4;j++){
			int xx = x + dx[j];
			int yy = y + dy[j];
			if(pass(xx,yy) && visited[xx][yy] && merge({x,y}, {xx,yy})) civilization--;//처음부터 붙어있는 문명들 통합 
		}
	}
	
	int year = 0;
	while(!q.empty()){
		if(civilization == 1){
			cout<<year;
			return 0;
		}
		year++;
		int sz = q.size();
		while(sz--){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for(int i=0;i<4;i++){
				int xx = x + dx[i];
				int yy = y + dy[i];
				if(!pass(xx,yy)) continue;
				
				if(visited[xx][yy] && merge({x,y},{xx,yy})) civilization--;//문명끼리 병합될때 
				
				if(!visited[xx][yy]){
					visited[xx][yy] = true;
					q.push({xx,yy});
					merge({x,y},{xx,yy});//황무지와 병합 
					
					for(int j=0;j<4;j++){//전파된 곳이 다른 문명과 맞닿아 있다면, 미리 병합해야함 
						int xxx = xx + dx[j];
						int yyy = yy + dy[j];
						if(!pass(xxx,yyy)) continue;
						if(visited[xxx][yyy] && merge({xx,yy},{xxx,yyy})) civilization--;
					}
				} 
			}
		}//1년 단위
		 
	}
	cout<<year;
	return 0;
}