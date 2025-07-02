#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;
struct Info{
    int b,cost;
};
vector<vector<Info>> graph;
vector<int> dist, parent;

int n,m;
bool bellman(){
    dist[1] = 0;

    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<graph[j].size();k++){
                int next = graph[j][k].b;
                int next_dist = dist[j] + graph[j][k].cost;
                if(dist[j] != -INF && next_dist > dist[next]){
                    dist[next] = next_dist;
                    parent[next] = j;
                }
            }
        }
    }


    int before = dist[n];
    for(int i=0;i<1000;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<graph[j].size();k++){
                int next = graph[j][k].b;
                int next_dist = dist[j] + graph[j][k].cost;
                if(dist[j] != -INF && next_dist > dist[next]){
                    dist[next] = next_dist;
                    parent[next] = j;
                }
            }
        }
    }

    int after = dist[n];
    return dist[n]!=-INF && before >= after;
}

void track(){
    int now = n;
    vector<int> answer;
    for(int now = n; now != -1; now = parent[now]){
        answer.push_back(now);
    }
    if(answer.back() != 1){
        cout<<"-1";
        return;
    }

    reverse(answer.begin(), answer.end());

    for(int a: answer) cout<<a<<' ';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    graph.resize(n+1);
    parent.resize(n+1, -1);
    dist.resize(n+1, -INF);
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }

    if(bellman()) track();
    else cout<<"-1";
    return 0;
}