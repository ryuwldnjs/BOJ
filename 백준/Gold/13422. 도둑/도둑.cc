#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

void solve(){
    ll n,m,k;cin>>n>>m>>k;
    vector<ll> money(n);
    for(int i=0;i<n;i++){
        cin>>money[i];
    }
    ll sum = 0;
    for(int i=0;i<m;i++){
        sum += money[i];
    }

    int answer = 0;
    for(int i=0;i<n;i++){
        if(sum < k) answer++;
        sum += money[(i + m)%n] - money[i];
    }
    if(n == m) answer = !!answer;
    cout<<answer<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}