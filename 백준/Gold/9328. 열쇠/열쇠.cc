#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
using pii=pair<int,int>;
queue<pii> q;
vector<vector<pii>> waiting;//알파벳별로 문 대기열

char map[105][105];
bool visited[105][105];
int t,h,w;
string str;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int key, answer;
bool pass(int x, int y){
	return 0<=x&&x<h && 0<=y&&y<w && map[x][y]!='*';
}
int verify(int x,int y){
	if('A'<=map[x][y]&&map[x][y]<='Z'){
		if((1<<(map[x][y]-'A'))&key)
			return 1;
		return 0;
	}
	return -1;
}

void dfs(int x, int y){
	if(visited[x][y]) return;
//	printf("%d,%d\n",x,y);
	//0.문서 발견
	if(map[x][y] == '$') answer++;
	//1.키 획득 
	else if('a'<= map[x][y]&&map[x][y] <='z'){
		key |= 1<<(map[x][y]-'a');
		//1.1. 해당 키를 기다리는 문들을 찾아 삼만리 
		for(int i=0;i<waiting[map[x][y]-'a'].size();i++){
			q.push(waiting[map[x][y]-'a'][i]);
		}
		waiting[map[x][y]-'a'] = vector<pii>();
	}
	//2.도어락 키 존재확인
	else if(verify(x,y) == 0){ //문을 만났는데 키가 없을때 
		waiting[map[x][y]-'A'].push_back({x,y});
		return;
	}
	visited[x][y] = true;
	
	for(int i=0;i<4;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		
		if(pass(xx,yy)){
			dfs(xx,yy);
		}
	}
}
int main(){
	cin>>t;
	while(t--){
		fill(&visited[0][0], &visited[104][104], false);
		key = answer = 0;
		waiting=vector<vector<pii>>(30);
		q = queue<pii>();
		
		
		cin>>h>>w;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cin>>map[i][j];
			}
		}
		cin>>str;
		if(str != "0") for(char x: str){
			key |= 1<<(x - 'a');
		}
		
		for(int i=0;i<h;i++){
//			if(map[i][0]=='.' || 'a'<=map[i][0]&&map[i][0]<='z' || verify(i,0)==1){
//				q.push({i,0});
//			}
//			if(map[i][w-1]=='.' || 'a'<=map[i][w-1]&&map[i][w-1]<='z' || verify(i,w-1)==1){
//				q.push({i,w-1});
//			}
			if(pass(i,0)) q.push({i,0});
			if(pass(i,w-1)) q.push({i,w-1});
		}
		for(int j=0;j<w;j++){
//			if(map[0][j]=='.' || 'a'<=map[0][j]&&map[0][j]<='z' || verify(0,j)==1){
//				q.push({0,j});
//			}
//			if(map[h-1][j]=='.' || 'a'<=map[h-1][j]&&map[h-1][j]<='z' || verify(h-1,j)==1){
//				q.push({h-1,j});
//			}
			if(pass(0,j)) q.push({0,j});
			if(pass(h-1,j)) q.push({h-1,j});
		}
		//입구 탐색 완료
		
		while(!q.empty()){
			pii start = q.front();
			q.pop();
			dfs(start.first, start.second);
		}
		
		
		cout<<answer<<'\n';
	}
	return 0;
}