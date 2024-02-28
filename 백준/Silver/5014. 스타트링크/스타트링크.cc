#include <bits/stdc++.h>
using namespace std;
int F,S,G,U,D;
queue<int> q;
bool visited[1000000+5];
int  dist[1000000+5];
bool pass(int x){
	return 1<=x&&x<=F && !visited[x];
}

int main(){
	cin>>F>>S>>G>>U>>D;
	
	q.push(S);
	visited[S] = true;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(now == G){
			cout<<dist[now];
			return 0;
		}
		
		if(pass(now + U)){
			q.push(now+U);
			visited[now + U] = true;
			dist[now + U] = dist[now] + 1;
		}
		if(pass(now - D)){
			q.push(now - D);
			visited[now - D] = true;
			dist[now - D] = dist[now] + 1;
		}
	}
	cout<<"use the stairs"; 
	return 0;
}