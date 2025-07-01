#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
const ll INF = (ll)1e15;
ll n;
vector<ll> salary;

ll solve(ll l ,ll r){
    if(l==r) return salary[l];
    
    ll mid = (l + r) / 2;
    ll ret = max(solve(l, mid), solve(mid+1, r));

    ll MIN = min(salary[mid], salary[mid+1]);

    ll lo=mid,hi=mid+1;
    while(lo > l || hi < r){
        MIN = min(MIN, min(salary[lo], salary[hi]));
        ret = max(ret, MIN * (hi-lo+1));

        if(lo > l && (hi == r || salary[lo-1] >= salary[hi+1])) lo--;
        else if(hi < r && (lo == l || salary[lo-1] <= salary[hi+1])) hi++;
    }
    MIN = min(MIN, min(salary[lo], salary[hi]));
    ret = max(ret, MIN * (hi-lo+1));
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    salary.resize(n+2);

    for(ll i=0;i<n;i++){
        cin>>salary[i];
    }
    if(n==0) cout<<0;
    else cout<<solve(0, n-1);
    return 0;
}