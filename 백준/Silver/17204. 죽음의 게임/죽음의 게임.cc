#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n,k;
int graph[155];

bool visited[155];
int dfs(int now, int cnt){
    if(now == k) return cnt;
    visited[now] = true;
    if(!visited[graph[now]]) return dfs(graph[now], cnt+1);
    
    return -1;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>graph[i];
    }

    cout<<dfs(0, 0);
    return 0;
}