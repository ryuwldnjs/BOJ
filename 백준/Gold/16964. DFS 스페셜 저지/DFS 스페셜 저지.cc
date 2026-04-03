#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n;
int parent[100000+5];
int child_cnt[100000+5];
set<int> graph[100000+5];
bool visited[100000+5];

void dfs(int now){
    visited[now] = true;

    for(int next: graph[now]){
        if(!visited[next]){
            parent[next] = now;
            child_cnt[now]++;
            dfs(next);
        }
    }
}

int solve(){
    int now = 1;
    int next;cin>>next;
    for(int i=2;i<=n;i++){
        cin>>next;
        
        if(graph[now].count(next)){
            child_cnt[now]--;
            now = next;
        }
        else if(child_cnt[now] > 0){ //자식 무시한 케이스
            return 0;
        }
        else{ //자식 다 방문해서 올라가야함
            while(child_cnt[now] == 0 && now != 1){
                now = parent[now];
            }
            if(graph[now].count(next)){
                child_cnt[now]--;
                now = next;
            }
            else return 0;
        }
    }

    return 1;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    dfs(1);

    cout<<solve();
    return 0;
}