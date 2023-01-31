#include <iostream>
#include <queue>
using namespace std;

bool visited[100000+50];
queue<pair<int,int>> q;
int n,k;

int shortest;
int cnt;
bool pass(int x){
	if(0<=x&&x<=100000) return true;
	return false;
}


int main(){
	cin>>n>>k;
	q.push({n,0});
	
	while(!q.empty()){
		int now = q.front().first;
		int dist = q.front().second;
		q.pop();
		
		visited[now] = true;
		//1+1 or 1*2두가지 경로가 생기므로, 큐를 처리할때 방문처리 
		if(now == k){
			if(shortest == 0) {
				shortest = dist;
				cnt++;
			}
			else if(shortest == dist) cnt++;
			continue;
		}
		if(pass(now*2) && !visited[now*2] || now*2 == k){
			q.push({now*2, dist+1});
		}
		if(pass(now-1) && !visited[now-1] || now-1 == k){
			q.push({now-1, dist+1});
		}
		if(pass(now+1) && !visited[now+1] || now+1 == k){
			q.push({now+1, dist+1});
		}
		
	}
	cout<<shortest<<'\n'<<cnt;
	
	return 0;
}