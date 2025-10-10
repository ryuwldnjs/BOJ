#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
struct MergeTree{
    vector<vector<ll>> tree;
    ll size;

    MergeTree(vector<ll> &arr){
        size = 1<<(32 - __builtin_clz(arr.size()));
        tree.resize(size*2);

        for(ll i=0;i<arr.size();i++){
            tree[i + size].push_back(arr[i]);
        }
        for(ll i=size-1;i>=1;i--){
            tree[i].resize(tree[i*2].size() + tree[i*2+1].size());
            merge(tree[i*2].begin(), tree[i*2].end(), tree[i*2+1].begin(), tree[i*2+1].end(), tree[i].begin());
        }


    }
    //[l,r]구간에서 val이하인 원소의 개수
    ll queryMIN(ll l, ll r, ll val){
        if(l > r) return 0;
        l += size;
        r += size;
        ll ret = 0;
        while(l <= r){
            if(l % 2 == 1) {
                ret += upper_bound(tree[l].begin(), tree[l].end(), val) - tree[l].begin();
                l++;
            }
            if(r % 2 == 0) {
                ret += upper_bound(tree[r].begin(), tree[r].end(), val) - tree[r].begin();
                r--;
            }
            l/=2; r/=2;
        }
        return ret;
    }

    //[l,r]구간에서 val이상인 원소의 개수
    ll queryMAX(ll l, ll r, ll val){
        if(l > r) return 0;
        l += size;
        r += size;
        ll ret = 0;
        while(l <= r){
            if(l % 2 == 1) {
                ret += tree[l].end() - lower_bound(tree[l].begin(), tree[l].end(), val);
                l++;
            }
            if(r % 2 == 0) {
                ret += tree[r].end() - lower_bound(tree[r].begin(), tree[r].end(), val);
                r--;
            }
            l/=2; r/=2;
        }
        return ret;
    }
};

// p[] 오름차순 기준으로 p[],q[] 정렬


vector<pii> arr;
vector<ll> a,b;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n; cin>>n;
    arr.resize(n);
    a.resize(n); b.resize(n);

    for(ll i=0;i<n;i++) cin>>arr[i].first;
    for(ll i=0;i<n;i++) cin>>arr[i].second;
    sort(arr.begin(), arr.end());

    for(ll i=0;i<n;i++){
        a[i] = arr[i].first;
        b[i] = arr[i].second;
    }

    MergeTree mergetree(b);

    ll answer = 0;
    //p[j] < p[i] && q[j] < q[i]인 개수 = min_cnt
    //p[i] < p[k] && q[i] < q[k]인 개수 = max_cnt
    // min_cnt * max_cnt의 합

    for(int i=0;i<n;i++){
        int idx = lower_bound(a.begin(), a.end(), a[i]) - a.begin() - 1;
        ll min_cnt = mergetree.queryMIN(0, idx, b[i]-1);
        
        idx = lower_bound(a.begin(), a.end(), a[i]+1) - a.begin();
        ll max_cnt = mergetree.queryMAX(idx, n-1, b[i]+1);
        
        answer += min_cnt * max_cnt;
    }

    cout<<answer;
    return 0;
}