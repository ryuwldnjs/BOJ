#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll INF = 1e18;
void solve(){
    priority_queue<ll> maxpq;
    priority_queue<ll, vector<ll>, greater<ll>> minpq;
    vector<ll> answer;
    maxpq.push(-INF);
    minpq.push(INF);
    ll n;cin>>n;
    for(ll i=0;i<n;i++){
        ll x;cin>>x;

        if(minpq.top() < x)minpq.push(x);
        else maxpq.push(x);
        
        if(maxpq.size() > minpq.size() + 1){
            minpq.push(maxpq.top());
            maxpq.pop();
        }

        if(maxpq.size() < minpq.size()){
            maxpq.push(minpq.top());
            minpq.pop();
        }

        if(i%2==0) answer.push_back(maxpq.top());

    }
    cout<<answer.size();
    
    for(int i=0;i<answer.size();i++){
        if(i%10 == 0) cout<<'\n';
        cout<<answer[i]<<' ';
    }
    cout<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}