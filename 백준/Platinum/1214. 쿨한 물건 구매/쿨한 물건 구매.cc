#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

// Px + Qy >= D
// P >= Q

// x = [0~Q-1] 체크

// x1=Q일때,
// PQ + Qy1 >= D
// = P*0 + Q(P+y1)
// 이미 x=0일때 해당 값을 구한거임

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll d,p,q;cin>>d>>p>>q;
    if(p < q) swap(p,q);

    // Px + Qy >= D
    // y >= ceil((D-Px) / Q)

    ll answer = 1e15;
    for(ll x=0;x<min(q, d/p+2);x++){
        ll y = ((d-p*x) + q-1) / q;
        answer = min(answer, p*x + q*y);
    }

    cout<<answer;
    return 0;
}