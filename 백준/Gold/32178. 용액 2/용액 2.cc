#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
ll n, psum, MIN=1e18, l,r, ans;
vector<pair<ll,ll> > psums;
int main(){
    cin>>n;
    psums.push_back(make_pair(0, 0));
    for(int i=1;i<=n;i++){
        ll x; cin>>x;
        psum += x;
        psums.push_back(make_pair(psum, i));
    }
    sort(psums.begin(), psums.end());
    for(int i=1;i<psums.size(); i++){
        ll diff = psums[i].first - psums[i-1].first;
        if(abs(diff) < MIN){
            MIN = abs(diff);
            ans = diff;
            l = psums[i-1].second;
            r = psums[i].second;
            if(l > r){
                swap(l, r);
                ans *= -1;

            };
        }
    }
    cout<<ans<<'\n';
    cout<<l+1<<' '<<r;
    return 0;  
}