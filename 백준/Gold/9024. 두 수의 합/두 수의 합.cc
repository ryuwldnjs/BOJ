#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

void solve(){
    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(), a.end());

    int MIN_gap = 2e8;
    int ret = 0;
    for(int i=0;i<n;i++){
        int idx = lower_bound(a.begin()+i+1, a.end(), k - a[i]) - a.begin();
        if(idx < a.size()){
            int gap = abs(a[idx] + a[i] - k);
            if(gap == MIN_gap) ret++;
            if(gap < MIN_gap){
                MIN_gap = gap;
                ret = 1;
            }
        }

        if(i+1 < idx){
            int gap = abs(a[idx-1] + a[i] - k);
            if(gap == MIN_gap) ret++;
            if(gap < MIN_gap){
                MIN_gap = gap;
                ret = 1;
            }
        }
    }

    cout<<ret<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}