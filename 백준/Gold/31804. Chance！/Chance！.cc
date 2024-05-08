#include <iostream>
#include <queue>
using namespace std;

struct Info{
	int val;
	int isChance;
	int dist;
};
int a,b;
bool visited[1000000+5][2];
void bfs(int start){
	queue<Info> q;
	q.push({start, 0, 0});
	visited[start][0] = true;
	
	while(!q.empty()){
		int now = q.front().val;
		int isChance = q.front().isChance;
		int dist = q.front().dist;
		q.pop();
		
		if(now == b){
			cout<<dist;
			return;
		}
		
		if(now+1 <= b && !visited[now+1][isChance]){
			q.push({now+1, isChance, dist+1});
			visited[now+1][isChance] = true;
		}
		if(2*now <= b && !visited[2*now][isChance]){
			q.push({2*now, isChance, dist+1});
			visited[2*now][isChance] = true;
		}
		if(10*now <= b && isChance == 0 && !visited[10*now][1]){
			q.push({10*now, 1, dist+1});
			visited[10*now][1] = true;
		}
		
	}
}
int main(){
	cin>>a>>b;
	
	bfs(a);
	
	return 0;
}