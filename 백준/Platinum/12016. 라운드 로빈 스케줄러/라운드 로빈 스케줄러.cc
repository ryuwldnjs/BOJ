/**
 * SCPC2024 예선2 : 라운드로빈 유사문제
 */

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct Info{
    ll idx;
    ll val;

    bool operator<(const Info& other)const{
        if(val == other.val) return idx < other.idx;
        return val < other.val;
    }
};

struct SegTree{
    vector<ll> tree;
    ll size;
    ll cnt;//세그트리에 들어있는 원소 개수
    SegTree(ll n){
        size = 1<<(32 - __builtin_clz(n));
        tree.resize(size * 2);
        cnt = 0;
    }

    void update(ll idx, ll val){
        idx += size;
        tree[idx] = val;
        while(idx > 1){
            idx /= 2;
            tree[idx] = tree[idx*2] + tree[idx*2+1];
        }
        cnt++;
    }

    ll query(ll l, ll r){
        l += size;
        r += size;
        ll ret = 0;
        while(l <= r){
            if(l%2==1) ret += tree[l++];
            if(r%2==0) ret += tree[r--];
            l /= 2; r /= 2;
        }
        return ret;
    }
};


void solve(){
    ll n;cin>>n;
    vector<Info> a(n+1);
    SegTree segtree(n+1);

    ll total = 0;
    for(ll i=1;i<=n;i++){
        ll val; cin>>val;
        a[i] = {i, val};
        total += val;
    }

    sort(a.begin(), a.end());
    
    vector<ll> ret(n+1);
    ret[n] = total;
    segtree.update(a[n].idx, 1);

    ll last = total;
    for(ll i=n-1;i>=1;i--){
        if(a[i+1].val == a[i].val){
            ll diff = segtree.query(a[i].idx+1, a[i+1].idx);
            ret[i] = last - diff;
        }
        else{
            ll diff = segtree.query(0, a[i+1].idx) 
                    + (a[i+1].val - a[i].val - 1) * segtree.cnt
                    + segtree.query(a[i].idx, n);
            ret[i] = last - diff;
        }

        last = ret[i];
        segtree.update(a[i].idx, 1);
    }

    vector<ll> answer(n+1);
    for(ll i=1;i<=n;i++){
        answer[a[i].idx] = ret[i];
    }

    for(ll i=1;i<=n;i++) cout<<answer[i]<<'\n';

}


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();
    return 0;
}