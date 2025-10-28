#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct SegTree{
    vector<ll> tree, lazy;
    int size, height;

    void build(vector<ll> &arr){
        int n = arr.size();
        size = 1<<(32 - __builtin_clz(n));
        // height = 32 - __builtin_clz(n);
        height = log2(size);
        tree = vector<ll>(size*2);
        lazy = vector<ll>(size*2);

        for(int i=0;i<n;i++){
            tree[size+i] = arr[i];
        }
        for(int i=size-1;i>=1;i--){
            tree[i] = tree[i*2] + tree[i*2+1];
        }
    }

    void apply(int idx, ll val, int len){
        tree[idx] += val * len;
        if(idx < size) lazy[idx] += val;
    }

    void push(int idx){
        for(int h=height; h>0; h--){
            int i = idx>>h;
            if(lazy[i] != 0){
                ll val = lazy[i];
                int len = 1<<(h-1);
                apply(i*2, val, len);
                apply(i*2+1, val, len);
                lazy[i] = 0;
            }
        }
    }

    void pull(int idx){
        while(idx > 1){
            idx/=2;
            tree[idx] = tree[idx*2] + tree[idx*2+1];
            int h = log2(idx);
            if(idx < size) tree[idx] += lazy[idx] * ((size >> h)+1);

        }
    }

    void update(int l, int r, int val){
        l += size; r += size;
        int l0 = l, r0 = r;

        push(l0); push(r0);

        int len = 1;
        while(l <= r){
            if(l%2 == 1) apply(l++, val, len);
            if(r%2 == 0) apply(r--, val, len);

            l/=2; r/=2; len*=2;
        }

        pull(l0); pull(r0);
    }

    ll query(int l ,int r){
        l += size;
        r += size;
        push(l); push(r);

        ll ret = 0;
        while(l <= r){
            if(l%2 == 1) ret += tree[l++];
            if(r%2 == 0) ret += tree[r--];
            
            l/=2; r/=2;
        }
        return ret;
    }
};

SegTree segtree;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    segtree.build(a);

    int m;cin>>m;

    while(m--){
        int com;cin>>com;
        if(com == 1){
            int a,b,c;cin>>a>>b>>c;
            segtree.update(a,b,c);
        }
        else{
            int x;cin>>x;
            cout<<segtree.query(x, x)<<'\n';
        }
    }
    return 0;
}