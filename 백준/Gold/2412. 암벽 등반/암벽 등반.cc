#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

set<pii> yList[200000+5];
int n,T;
vector<pii> dots;
vector<vector<int>> graph;

void makeGraph(){
    for(int i=0;i<=n;i++){
        auto [x,y] = dots[i];

        for(int dy=-2;dy<=2;dy++){
            int yy = y + dy;
            if(yy < 0) continue;

            auto begin = yList[yy].lower_bound({x-2, -1});
            auto end = yList[yy].upper_bound({x+3, -1});

            for(auto it=begin; it!=end; it++){
                int idx = it->second;
                graph[i].push_back(idx);
            }

        }
    }
}

int bfs(int start){
    queue<pii> q; // [idx, cost]
    vector<bool> visited(n+1);

    q.push({start, 0});
    visited[start] = true;

    while(!q.empty()){
        auto [now, cost] = q.front(); q.pop();
        // printf("%d %d\n", now, cost);
        //정상
        if(dots[now].second == T){
            return cost;
        }

        for(int next: graph[now]){
            if(!visited[next]){
                visited[next] = true;
                q.push({next, cost + 1});
            }
        }
    }
    return -1;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>T;
    graph.resize(n+1);
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        dots.push_back({a,b});
        yList[b].insert({a, i});
    }
    dots.push_back({0,0});
    // y[0].insert({0, n});

    makeGraph();

    cout<<bfs(n);
    return 0;
}