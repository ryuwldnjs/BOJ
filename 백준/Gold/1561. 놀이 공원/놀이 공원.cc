#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;

ll n,m;
vector<ll> a;
// 시간x분일때, 최소 n명이상이 탑승을 했는가?

bool able(ll x){
    ll cnt = 0;
    for(ll i=0;i<m;i++){
        cnt += (x + a[i]-1) / a[i];
    }
    return n <= cnt;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    a.resize(m);
    for(ll i=0;i<m;i++){
        cin>>a[i];
    }


    ll lo = -1, hi = (ll)1e15;
    for(ll i=0;i<100;i++){
        ll mid = (lo+hi)/2;

        if(able(mid)) hi = mid;
        else lo = mid;
        // printf("%lld\n", mid);
    }


    //현재까지 탑승한 사람수
    ll target = hi;
    if(able(hi)) target--;

    // printf("target:%lld\n", target);
    ll now_num = 0;
    for(ll i=0;i<m;i++){
        now_num += (target + a[i] - 1) / a[i];
        // printf("%d\n", now_num);

    }

    
    for(ll i=0; i<m && now_num < n; i++){
        if(target % a[i] == 0) now_num++;
        // printf("%d : ", now_num);
        if(now_num == n){
            cout<<i+1;
            return 0;
        }
    }



    return 0;
}