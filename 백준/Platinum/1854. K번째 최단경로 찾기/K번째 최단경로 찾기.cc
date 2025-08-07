#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int b,cost;

    bool operator<(const Info&other)const{
        return cost > other.cost;
    }
};
vector<Info> graph[1005];
priority_queue<int> dist[1005];
int n,m,k;
void dijkstra(){
    queue<Info> q;

    q.push({1, 0});
    dist[1].push(0);

    while(!q.empty()){
        auto [now, cost] = q.front();
        q.pop();

        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].b;
            int next_cost = cost + graph[now][i].cost;

            if(dist[next].size() < k || dist[next].top() > next_cost){
                q.push({next, next_cost});
                dist[next].push(next_cost);
                if(dist[next].size() > k) dist[next].pop();
            }
        }
    }


}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }

    dijkstra();

    for(int i=1;i<=n;i++){
        while(dist[i].size() > k) dist[i].pop();
        
        if(dist[i].size() < k) cout<<"-1\n";
        else cout<<dist[i].top()<<'\n';
    }
    return 0;
}