#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    ll b,cost;
};
vector<vector<Info>> graph;
vector<ll> subtree, answer;
vector<bool> visited;
ll sum;//1번노드 기준최단거리 합
ll n;
//1번노드 기준 각각 서브트리 개수 저장
ll dfs(int now){
    visited[now] = true;

    subtree[now] = 1;
    for(auto [next, next_dist]: graph[now]){
        if(!visited[next]){
            subtree[now] += dfs(next);
            sum += subtree[next] * next_dist;
        }
    }
    return subtree[now];
}


void dfs2(int now, ll sum){
    visited[now] = true;
    answer[now] = sum;
    for(auto [next, next_dist]: graph[now]){
        if(!visited[next]){
            ll next_sum = sum + next_dist * (n - subtree[next]*2);
            dfs2(next, next_sum);
        }
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    graph.resize(n+1);
    subtree.resize(n+1);
    answer.resize(n+1);
    visited.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b,c;cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    dfs(1);
    visited = vector<bool>(n+1);
    dfs2(1, sum);

    for(int i=1;i<=n;i++){
        cout<<answer[i]<<'\n';
    }
    return 0;
}