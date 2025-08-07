#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll INF = 1e17;
struct SegTree{
    vector<ll> tree;
    int size;
    SegTree(int n){
        size = 1<<(32 - __builtin_clz(n));
        tree.resize(size * 2, -INF);
    }

    void update(int idx, ll val){
        idx += size;
        tree[idx] = val;

        while(idx > 1){
            idx /= 2;
            tree[idx] = max(tree[idx*2], tree[idx*2+1]);
        }
    }

    ll query(int l, int r){
        l += size;
        r += size;
        ll ret = -INF;
        while(l <= r){
            if(l%2 == 1) ret = max(ret, tree[l++]);
            if(r%2 == 0) ret = max(ret, tree[r--]);
            l /= 2; r /= 2; 
        }
        return ret;
    }
    void print(){
        for(int i=0;i<size;i++) printf("%lld ",tree[i+size]);
        printf("\n");
    }
};

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n,k;cin>>n>>k;
    vector<ll> psum(n+1 + 5), dp(n+1);
    SegTree segtree(n+1);

    for(int i=1;i<=n;i++){
        cin>>psum[i];
        psum[i] += psum[i-1];
    }

    dp[0] = 0;
    segtree.update(0, dp[0] - psum[1]);
    
    //첫 k개까지는 확실하게 소잡을수있음
    for(int i=1;i<=k;i++){
        dp[i] = psum[i];
        segtree.update(i, dp[i] - psum[i+1]);
    }
    // segtree.print();

    for(int i=k+1;i<=n;i++){
        dp[i] = segtree.query(i-k-1, i-1) + psum[i];
        segtree.update(i, dp[i] - psum[i+1]);
    }

    // for(int i=1;i<=n;i++) printf("%d ",dp[i]);
    // printf("\n");

    ll answer = *max_element(dp.begin(), dp.end());
    cout<<answer;
    return 0;
}