#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
using ll=long long;

vector<vector<ll>> graph;
vector<ll> cost, total_cost;//단일 비용과 누적 비용
vector<bool> visited;

//dfs[i]: 이미 택배를 싣고 i 노드를 방문했을때의 비용
ll dfs(ll now){
    visited[now] = true;
    ll ret = 0; //상하차 횟수

    ll MAX = 0;
    for(ll i=0;i<graph[now].size();i++){
        ll next = graph[now][i];
        if(visited[next]) continue;

        ret += dfs(next);
        MAX = max(MAX, total_cost[next]);
        total_cost[now] += total_cost[next];
    }
    if(now != 1) ret += 2LL*(total_cost[now] - MAX);
    //1번노드는 재상하차 과정없이 바로 싣으면 됨
    
    ret += cost[now];
    total_cost[now] += cost[now];
    // printf("%d %d %d\n", now, ret, total_cost[now]);
    return ret;
}

ll answer = 0;
int main(){
    ll n; cin>>n;
    graph.resize(n+1);
    visited.resize(n+1);
    cost.resize(n+1);
    total_cost.resize(n+1);
    for(ll i=1;i<=n;i++){
        cin>>cost[i]; 
    }
    cost[1] = 0; //어차피 바로 도착임

    for(ll i=0;i<n-1;i++){
        ll a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    answer = dfs(1);
    answer += total_cost[1];
    cout<<answer;
    return 0;
}