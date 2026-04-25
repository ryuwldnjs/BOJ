#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;

int dist[105][105];
int n,m;

void floyd(){
    for(int i=1;i<=n;i++) dist[i][i] = 0;
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    fill(&dist[0][0], &dist[104][104], INF);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        dist[a][b] = dist[b][a] = 1;
    }

    floyd();

    int answer = INF;
    int a=-1,b=-1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int ret = 0;
            for(int k=1;k<=n;k++){
                ret += min(dist[i][k], dist[j][k]);
            }
            if(answer > ret){
                answer = ret;
                a = i;
                b = j;
            }
        }
    }

    cout<<a<<' '<<b<<' '<<answer*2;
    return 0;
}