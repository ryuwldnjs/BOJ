#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;

ll n,t;
vector<ll> a;
bool able(ll mid){
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    if(mid == 0) return false;

    for(ll i=0;i<n;i++){
        //더이상 안봐도 되는 스케줄 삭제
        while(!pq.empty()){
            ll top = pq.top();
            if(top + t - 1 < a[i]) pq.pop();
            else break;
        }

        //세미나실 여유가 있으면 일단 넣기
        if(pq.size() < mid){
            pq.push(max(a[i], t));
            continue;
        }
        // 현재 pq사이즈는 mid

        //가장 과거에 있는 예약정보를 기준으로 갱신
        ll top = pq.top();
        pq.pop();

        //이전 세미나가 권리 침해중
        if(top >= a[i]) return false;
        pq.push(top + t);
    }
    return true;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>t;
    a.resize(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    

    ll l=0,r=500000;
    // cout<<able(0);
    for(ll i=0;i<100;i++){
        ll mid = (l+r)/2;
        if(able(mid)) r = mid;
        else l = mid;
    }
    if(able(l)) cout<<l;
    else cout<<r;
    return 0;
}