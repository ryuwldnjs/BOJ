#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n,m;cin>>n>>m;
    vector<ll> w(n+2), delta(n+2);
    for(int i=1;i<=n-1;i++){
        cin>>w[i];
    }
    for(int i=0;i<m;i++){
        ll u,v,x;cin>>u>>v>>x;
        delta[u] += x;
        delta[v] -= x;
    }
    for(int i=1;i<=n+1;i++){
        delta[i] += delta[i-1];
    }

    //i번 간선 : i와 i+1도시 사이의 길
    for(int i=1;i<=n-1;i++){
        ll car = delta[i];
        
        ll x = car / w[i]; //모든 차선 골고루
        ll a = car % w[i]; //1대씩 더 할당해줘야함
        ll b = w[i] - a;
        ll answer = (x+1) * (x+1) * a + x * x * b;
        cout<<answer<<'\n';
    }
    return 0;
}