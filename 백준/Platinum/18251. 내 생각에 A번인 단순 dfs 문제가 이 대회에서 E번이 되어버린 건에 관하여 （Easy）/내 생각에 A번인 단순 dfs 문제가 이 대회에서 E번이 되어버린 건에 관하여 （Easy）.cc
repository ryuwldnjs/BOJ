#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
#define HEIGHT 18
#define INF 1e17
ll n;
ll tree[300000];
ll a[20][300000];
ll psum[20][300000];
void draw(ll idx, ll y, ll x, ll dx){
    if(idx > n) return;
    a[y][x] = tree[idx];
    draw(idx*2, y+1, x - dx, dx/2);
    draw(idx*2+1, y+1, x + dx, dx/2);
}


ll getPsum(ll y1 ,ll y2, ll x){
    return psum[y2][x] - psum[y1-1][x] - psum[y2][x-1] + psum[y1-1][x-1];
}

// [y1, y2] 높이 구간 고정한뒤
ll solve(ll y1, ll y2){
    ll ret = 0;
    ll dp = 0;
    for(ll x=1;x<=n;x++){
        ll val = getPsum(y1, y2, x);
        if(dp + val < 0) dp = 0;
        else dp = dp + val;

        ret = max(ret, dp);
    }
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    ll MAX = -INF;
    for(ll i=1;i<=n;i++) {
        cin>>tree[i];
        MAX = max(MAX, tree[i]);
    }
    if(MAX < 0){
        cout<<MAX;
        return 0;
    }

    draw(1, 1, n/2+1, n/4+1);
    for(ll i=1;i<=HEIGHT;i++){
        for(ll j=1;j<=n;j++){
            psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + a[i][j];
        }
    }

    ll answer = -INF;
    for(ll i=1;i<=HEIGHT;i++){
        for(ll j=i;j<=HEIGHT;j++){
            answer = max(answer, solve(i,j));
        }
    }
    cout<<answer;
    return 0;
}