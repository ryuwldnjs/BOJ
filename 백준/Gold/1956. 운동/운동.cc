#include <iostream>
#include <vector>
#define INF 1000000000
using namespace std;
//vector<pair<int,int> > vec[405];
int dist[405][405];
int v,e,a,b,cost,ans=1234567890; 
int main(){
	cin>>v>>e;
	//플로이드 거리 무한대 설정 
	for(int i=1;i<=v;i++){
		for(int j=1;j<=v;j++){
			dist[i][j]=INF;
		}
	}
	for(int i=0;i<e;i++){
		cin>>a>>b>>cost;
		dist[a][b]=cost;
	}
	
	//플로이드 3중for문 
	for(int k=1;k<=v;k++){
		for(int i=1;i<=v;i++){
			for(int j=1;j<=v;j++){
				if(dist[i][j]> dist[i][k]+dist[k][j])
					dist[i][j] = dist[i][k]+dist[k][j];
			}
		}
	}
	for(int i=1;i<=v;i++){
		ans = min(ans, dist[i][i]);
	}
	if(ans!=INF) cout<<ans;
	else cout<<"-1";
	return 0;
}