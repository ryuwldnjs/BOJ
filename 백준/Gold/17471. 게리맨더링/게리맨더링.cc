#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;
vector<vector<int>> graph;
vector<int> people, party;
vector<bool> visited;
int n;

pii& operator+=(pii &a, const pii &b) {
    a.first += b.first;
    a.second += b.second;
    return a;
}

pii dfs(int now){ //마을수, 사람수
    visited[now] = true;
    pii ret = {1, people[now]};
    for(int next: graph[now]){
        if(visited[next]) continue;
        if(party[now] == party[next]) ret += dfs(next);
    }
    return ret;
}
int solve(int idx){
    if(idx == n+1){
        visited = vector<bool>(n+1);
        vector<pii> parties;
        for(int i=1;i<=n;i++){
            if(!visited[i]) parties.push_back(dfs(i));
        }
        if(parties.size() != 2) return INF;//지역구 구분 불가
        return abs(parties[0].second - parties[1].second);
    }

    int ret = INF;

    ret = min(ret, solve(idx+1));
    party[idx] = 1;
    ret = min(ret, solve(idx+1));
    party[idx] = 0;
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    people.resize(n+1);
    graph.resize(n+1);
    party.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>people[i];
    }
    for(int i=1;i<=n;i++){
        int j;cin>>j;
        while(j--){
            int x;cin>>x;
            graph[i].push_back(x);
        }
    }
    // visited = vector<bool>(n+1);
    // party[2] = party[3] = party[5] = party[6] = 1;
    // pii a = dfs(1);
    // pii b = dfs(n);
    // printf("%d %d", a.first+b.first, a.second-b.second);
    
    int answer = solve(1);
    if(answer == INF) cout<<-1;
    else cout<<answer;
    return 0;
}