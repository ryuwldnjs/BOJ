#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int n, a,b;
vector<int> arr;

bool pass(int x){
    return 0<x&&x<=n;
}
void bfs(){
    queue<pii> q;
    vector<bool> visited(n+1);
    q.push({a, 0});

    while(!q.empty()){
        auto [now, cost] = q.front();
        q.pop();
        if(now == b){
            cout<<cost;
            return;
        }
        for(int i=1;;i++){
            int next = now + arr[now] * i;
            if(!pass(next)) break;
            if(!visited[next]){
                q.push({next, cost+1});
                visited[next] = true;
            }
        }
        for(int i=1;;i++){
            int next = now - arr[now] * i;
            if(!pass(next)) break;
            if(!visited[next]){
                q.push({next, cost+1});
                visited[next] = true;
            }
        }
    }

    cout<<-1;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    arr.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cin>>a>>b;
    bfs();
    return 0;
}