#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int n,m;
int graph[205][205], dist[205][205], nextHop[205][205];

void floyd(){
    for(int i=1;i<=n;i++) dist[i][i] = 0;

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    nextHop[i][j] = nextHop[i][k];
                }
            }
        }
    }


}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    fill(&dist[0][0], &dist[204][204], INF);

    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        dist[a][b] = dist[b][a] = c;
        nextHop[a][b] = b;
        nextHop[b][a] = a;
    }

    floyd();

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            // printf("%d ", dist[i][j]);
            if(dist[i][j]) cout<<nextHop[i][j]<<' ';
            else cout<<"- ";
        }
        cout<<'\n';
    }
    return 0;
}