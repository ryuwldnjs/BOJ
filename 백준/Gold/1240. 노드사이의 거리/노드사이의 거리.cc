#include <iostream>
#define INF 987654321
using namespace std;

int dis[1005][1005];
int n,m,a,b,c;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i == j)
				dis[i][j] = 0;
			else
				dis[i][j] = INF;
			
		}
	}
	
	
	for(int i=0;i<n-1;i++){
		cin>>a>>b>>c;
		dis[a][b] = dis[b][a] = c;
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][j] > dis[i][k] + dis[k][j])
					dis[i][j] = dis[i][k] + dis[k][j];
			}
		}
	}
	while(m--){
		cin>>a>>b;
		cout<<dis[a][b]<<'\n';
	}
	return 0;
}