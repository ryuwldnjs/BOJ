#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

ll n,m;
vector<ll> arr;
queue<ll> q;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    arr.resize(n);
    ll total = 0;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        total += arr[i];
        q.push(arr[i]);
    }

    while(!q.empty()){
        m %= total;
        ll now = q.front();
        q.pop();
        if(m < now) total -= now;
        else{
            q.push(now);
            m -= now;
        }
    }
    cout<<m;
    return 0;
}