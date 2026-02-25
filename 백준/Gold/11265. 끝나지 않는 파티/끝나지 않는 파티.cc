#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n,m;
int dist[505][505];
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>dist[i][j];
        }
    }

    floyd();

    while(m--){
        int a,b,c; cin>>a>>b>>c;
        if(dist[a][b] <= c) cout<<"Enjoy other party\n";
        else cout<<"Stay here\n";
    }
    return 0;
}