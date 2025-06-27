#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct SegTree{
    vector<ll> tree;
    int size;
    SegTree(int n){
        size = 1<<(32 - __builtin_clz(n));
        tree.resize(size * 2);
    }

    void update(int idx, ll diff){
        idx += size;
        tree[idx] += diff;

        while(idx > 1){
            idx /= 2;
            tree[idx] = tree[idx*2] + tree[idx*2+1];
        }
    }

    ll query(int l, int r){
        l += size;
        r += size;
        ll ret = 0;
        while(l<=r){
            if(l%2 == 1) ret += tree[l++];
            if(r%2 == 0) ret += tree[r--];
            l/=2; r/=2;
        }
        return ret;
    }
};

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,q;cin>>n>>q;
    SegTree segtree(n);

    while(q--){
        ll a,b,c;cin>>a>>b>>c;
        if(a == 1) segtree.update(b, c);
        else cout<<segtree.query(b, c)<<'\n';
    }
    return 0;
}