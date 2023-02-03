#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1000000000 // 1234567890로 하면 오버플로 발생 
using namespace std;

int dist[105][105];
int item[105];
int n,m,r, a,b,c;
int MAX = -INF;

void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}

int main(){
	cin>>n>>m>>r;
	for(int i=1;i<=n;i++) {
		cin>>item[i];
		fill(dist[i], dist[i]+105, INF);
		dist[i][i] = 0;
	}
	
	for(int i=0;i<r;i++){
		cin>>a>>b>>c;
		dist[a][b] = dist[b][a] = c;
	}
	
	floyd();
	
	for(int i=1;i<=n;i++){ //i번으로 떨어진 후 탐색 
		int sum=0;
		for(int j=1;j<=n;j++){ //i->j로 수색 
			if(dist[i][j] <= m) sum += item[j];
		}
		
		MAX = max(MAX, sum); 
	}
	
	cout<<MAX;
	return 0;
}