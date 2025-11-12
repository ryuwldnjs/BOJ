#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
pii operator<(const pii& a, const pii& b){
    if(a.first < b.first) return a;
}

struct SegTree{
    vector<pii> tree; // (val, idx)
    ll size;
    
    void build(vector<ll> &a){
        size = 1<<(32 - __builtin_clz(a.size()));
        tree.resize(size*2);

        for(ll i=0;i<a.size();i++){
            tree[i + size] = {a[i], i};
        }
        for(ll i=size-1;i>=1;i--){
            tree[i] = min(tree[i*2], tree[i*2+1]);
        }
    }

    //[l,r]구간에서 최솟값의 idx
    ll query(ll l, ll r){
        l += size;
        r += size;

        pii ret = {1e9, -1};
        while(l <= r){
            if(l%2==1) ret = min(ret, tree[l++]);
            if(r%2==0) ret = min(ret, tree[r--]);
            l/=2; r/=2;
        }

        return ret.second;
    }

};

struct Info{
    ll val;
    ll l, r;

    bool operator<(const Info &other)const{
        return val < other.val;
    }
};

vector<ll> a, psum;
SegTree segtree;

Info solve(ll l, ll r){
    if(l > r) return {-1, -1, -1};

    ll pivot = segtree.query(l ,r);

    Info ret = {(psum[r] - psum[l-1]) * a[pivot], l ,r};
    ret = max(ret, solve(l, pivot-1));
    ret = max(ret, solve(pivot+1, r));
    // printf("%d %d %d\n", ret.val, ret.l, ret.r);
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n;cin>>n;
    a.resize(n+1);
    psum.resize(n+1);

    for(ll i=1;i<=n;i++) cin>>a[i];
    for(ll i=1;i<=n;i++) psum[i] = psum[i-1] + a[i];
    segtree.build(a);

    Info answer = solve(1, n);
    cout<<answer.val<<'\n';
    cout<<answer.l<<' '<<answer.r<<'\n';
    return 0;
}