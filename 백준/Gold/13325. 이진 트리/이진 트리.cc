#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;

ll n, MAX;
ll edges[1<<(22)];
ll answer = 0;


ll solve(ll idx, ll sum){
    if(idx*2 >= MAX){ //리프노드
        return sum;
    }

    ll l = solve(idx*2, sum + edges[idx*2]);
    ll r = solve(idx*2+1, sum + edges[idx*2+1]);

    answer += abs(l-r);
    return max(l, r);
}


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    MAX = (1<<(n+1));

    for(ll i=2;i<MAX; i++){
        cin>>edges[i];
        answer += edges[i];
    }

    solve(1, 0);
    
    cout<<answer;
    return 0;
}