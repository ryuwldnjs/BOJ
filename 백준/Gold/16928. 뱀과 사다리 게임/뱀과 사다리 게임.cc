#include <iostream>
#include <queue>
#define INF 1234567890
using namespace std;

int teleport[101], d[101];
bool visited[101];
queue<int> q; //idx, dist
int n,m,a,b, MIN = INF;
int main(){
	cin>>n>>m;
	fill(d+2, d+101, INF);
	for(int i=0;i<n+m;i++){
		cin>>a>>b;
		teleport[a] = b;
	}
	q.push(1);
	
	while(!q.empty()){
		int now = q.front();
		int next;
		q.pop();
	//	printf("%d, %d\n", now, dist);
		
		
		
		next = teleport[now];
		if(next){ //사다리나 뱀있으면 강제이송 ㅠ 
			if(d[now] < d[next]){
				q.push(next);
				d[next] = d[now];
			}
			continue; //주사위 못굴림 
		}
		
		for(int i=1;i<=6;i++){
			next = now + i;
			
			if(d[now]+1 < d[next] && next <=100){
				q.push(next);
				d[next] = d[now] + 1;
			}
		}
		
	}
	
	cout<<d[100];
	return 0;
}