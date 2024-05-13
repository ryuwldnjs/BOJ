#include <iostream>
#include <queue>
using namespace std;
using pii=pair<int,int>;
int a,k;
bool visited[1000000+5];
queue<pii> q;
bool pass(int x){
	return x <= 1000000 && visited[x] == false;
}

int main(){
	cin>>a>>k;
	
	q.push({a, 0});
	visited[a] = true;
	
	while(!q.empty()){
		int now = q.front().first;
		int dist = q.front().second;
		q.pop();
		
		if(now == k){
			cout<<dist;
			return 0;
		}		
		if(pass(now + 1)){
			visited[now+1] = true;
			q.push({now+1, dist+1});	
		}
		if(pass(2 * now)){
			visited[2 * now] = true;
			q.push({2 * now, dist+1});	
		} 
	}
	return 0;
}