#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
const ll MOD = 1000000007;

struct Info{
    ll val1; //실제값 + 오른쪽으로부터의 거리
    ll val2; //실제값 + 왼쪽으로부터의 거리
    ll cnt;

    Info operator+(const Info &other)const{
        Info ret;
        ret.val1 = (val1 + other.val1) % MOD;
        ret.val2 = (val2 + other.val2) % MOD;
        ret.cnt = cnt + other.cnt;
        return ret;
    }
};
struct SegTree{
    vector<Info> tree;
    ll size;

    SegTree(ll n){
        size = 1<<(32 - __builtin_clz(n));
        tree.resize(size * 2);
    }

    //단일 추가
    void update(ll idx){
        idx += size;
        tree[idx].val1 += -idx;
        tree[idx].val2 += idx;
        tree[idx].val1 %= MOD;
        tree[idx].val2 %= MOD;
        
        tree[idx].cnt += 1;

        while(idx > 1){
            idx /= 2;
            tree[idx] = tree[idx*2] + tree[idx*2+1];
        }
    }

    //[0, idx] : val1, [idx, size-1] : val2각 구간 
    ll query(ll idx){
        ll l=size, r=size+idx;
        ll ret = 0;
        while(l <= r){
            if(l%2==1) ret += (tree[l].val1 + tree[l++].cnt*(size+idx)); 
            if(r%2==0) ret += (tree[r].val1 + tree[r--].cnt*(size+idx));
            ret %= MOD;
            l /= 2; r /= 2;
        }

        l=size+idx, r=size+size-1;
        while(l <= r){
            if(l%2==1) ret += (tree[l].val2 - tree[l++].cnt*(size+idx)); 
            if(r%2==0) ret += (tree[r].val2 - tree[r--].cnt*(size+idx));
            ret %= MOD;
            l /= 2; r /= 2;
        }

        ret %= MOD;
        return ret;
    }
};

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n;cin>>n;
    SegTree segtree(200000+5);

    ll answer = 1;
    for(ll i=0;i<n;i++){
        ll x;cin>>x;

        if(i>0) answer *= segtree.query(x);
        answer %= MOD;
        segtree.update(x);
    }

    answer = (answer + MOD) % MOD;
    cout<<answer;
    return 0;
}