#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;

ll n;
vector<ll> a, graph[105];

vector<bool> visited;
vector<ll> answer;
ll dfs(ll now, ll depth){
    ll ret = depth;
    visited[now] = true;
    answer.push_back(a[now]);

    for(ll next: graph[now]){
        if(!visited[next]) ret = max(ret, dfs(next, depth+1));
    }
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    a.resize(n);

    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(a[i] == a[j]*3) graph[i].push_back(j);
            if(a[i]*2 == a[j]) graph[i].push_back(j);
        }
    }

    for(ll i=0;i<n;i++){
        visited = vector<bool>(n);
        answer = vector<ll>();

        ll depth = dfs(i, 1);
        if(depth == n){
            break;
        }
    }
    
    for(ll i:answer) cout<<i<<' ';

    return 0;
}