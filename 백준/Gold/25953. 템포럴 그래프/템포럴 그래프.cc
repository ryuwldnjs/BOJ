#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;

vector<int> dist, tmp;
int n,t,m;
int s,e;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>t>>m;
    cin>>s>>e;

    dist.resize(n, INF);
    dist[s] = 0;
    tmp = dist;

    for(int time=0;time<t;time++){
        for(int i=0;i<m;i++){
            int a,b,c;cin>>a>>b>>c;
            tmp[a] = min(tmp[a], dist[b] + c);
            tmp[b] = min(tmp[b], dist[a] + c);
        }
        dist = tmp;
    }

    if(dist[e] == INF) cout<<-1;
    else cout<<dist[e];
    return 0;
}