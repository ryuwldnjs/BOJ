#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
const int INF = 1e9;
struct SegTree{
    vector<ll> MIN, MAX;
    ll size;
    SegTree(ll n){
        size = 1<<(32 - __builtin_clz(n));
        MIN.resize(size * 2);
        MAX.resize(size * 2);

        for(ll i=0;i<n;i++){
            MIN[i + size] = i;
            MAX[i + size] = i;
        }
        for(ll i = size-1;i>=1;i--){
            MIN[i] = min(MIN[i*2], MIN[i*2+1]);
            MAX[i] = max(MAX[i*2], MAX[i*2+1]);
        }
    }

    //a,b교체
    void exchange(ll a, ll b){
        a += size; b += size;
        swap(MIN[a] ,MIN[b]);
        swap(MAX[a] ,MAX[b]);
        while(a > 1){
            a /= 2;
            MIN[a] = min(MIN[a*2], MIN[a*2+1]);
            MAX[a] = max(MAX[a*2], MAX[a*2+1]);
        }
        while(b > 1){
            b /= 2;
            MIN[b] = min(MIN[b*2], MIN[b*2+1]);
            MAX[b] = max(MAX[b*2], MAX[b*2+1]);
        }
    }
    // [l,r]구간의 최대 최소
    bool query(ll l, ll r){
        ll ret_min=INF, ret_max=-INF;
        
        ll a = l + size, b = r + size;
        while(a <= b){
            if(a%2 == 1){
                ret_min = min(ret_min, MIN[a]);
                ret_max = max(ret_max, MAX[a++]);
            }
            if(b%2 == 0){
                ret_min = min(ret_min, MIN[b]);
                ret_max = max(ret_max, MAX[b--]); 
            }
            a/=2; b/=2;
        }
        return ret_min==l && ret_max==r;
    }
};
void solve(){
    ll n,k;cin>>n>>k;
    SegTree segtree(n);
    while(k--){
        ll q,a,b;cin>>q>>a>>b;
        if(q == 0){
            segtree.exchange(a,b);
        }
        else{
            if(segtree.query(a,b)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll t; cin>>t; while(t--) solve();
    return 0;
}