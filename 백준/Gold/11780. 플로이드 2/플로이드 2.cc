#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;
struct Info{
    int b, cost;
};
vector<vector<int>> dist(105, vector<int>(105, INF));
vector<vector<Info>> graph(105);
int n,m;
void printPath(int s, int e){
    vector<int> path;

    while(e != s && dist[s][e] != INF){
        for(auto [prev, cost]: graph[e]){
            if(dist[s][e] == dist[s][prev] + cost){
                path.push_back(e);
                e = prev;
                break;
            }
        }
    }
    if(path.empty()){
        cout<<"0\n";
        return;
    }

    path.push_back(s);
    cout<<path.size()<<' ';
    for(auto it=path.rbegin(); it!=path.rend(); it++){
        cout<<*it<<' ';
    }
    cout<<'\n';
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) dist[i][i] = 0;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        dist[a][b] = min(dist[a][b], c);
        graph[b].push_back({a,c});//역추적 그래프
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j] == INF) cout<<"0 ";
            else cout<<dist[i][j]<<' ';
        }
        cout<<'\n';
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printPath(i,j);
        }
    }
    return 0;
}