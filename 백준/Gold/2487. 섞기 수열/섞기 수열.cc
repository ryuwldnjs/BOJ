#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int lcm(int a, int b){
    return a / gcd(a,b) * b;
}

int n;
int a[20005], to[20005];

bool visited[20005];
int dfs(int now){
    int ret = 1;
    visited[now] = true;
    if(!visited[to[now]]) ret += dfs(to[now]);
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        to[x] = i;
    }

    int answer = 1;
    for(int i=1;i<=n;i++){
        if(visited[i]) continue;
        int cnt = dfs(i);
        answer = lcm(answer, cnt);
    }

    cout<<answer;
    return 0;
}