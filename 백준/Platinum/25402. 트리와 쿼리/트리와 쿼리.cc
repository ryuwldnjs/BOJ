#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
vector<bool> canAccess;
vector<vector<int>> graph;

int dfs(int now){
    canAccess[now] = false;
    
    int ret = 1;
    for(int next:graph[now]){
        if(canAccess[next]) ret += dfs(next);
    }
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    graph.resize(n+1);
    canAccess.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    int q;cin>>q;
    while(q--){
        int k;cin>>k;
        vector<int> s(k);
        for(int i=0;i<k;i++){
            cin>>s[i];
            canAccess[s[i]] = true;
        }
        
        ll answer = 0;
        for(int i=0;i<k;i++){
            if(!canAccess[s[i]]) continue;
            ll nodes = dfs(s[i]);
            answer += nodes * (nodes-1) / 2;
        }
        cout<<answer<<'\n';
    }
    return 0;
}