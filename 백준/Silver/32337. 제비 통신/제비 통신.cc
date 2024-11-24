#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
using ll=long long;

using pii=pair<ll,ll>;
/**
 * L: mx + y + c = 0;
 * y = mx + c
 * y = mx - m*x1 + y1
 * 선분 정의: m과 c
 */
// 사용자 정의 해시 함수
struct PairHash {
    size_t operator()(const pii& p) const {
        return hash<ll>()(p.first) ^ (hash<ll>()(p.second) << 1LL);
    }
};

unordered_map<pii, ll, PairHash> um;
vector<ll> slope;
ll n,m, ans;
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        ll x; cin>>x;
        slope.push_back(x);
    }
    for(int i=0;i<n;i++){
        ll x1,y1; cin>>x1>>y1;
        for(int j=0;j<m;j++){
            ll c = -slope[j]*x1 + y1;
            um[{slope[j], c}]++;
        }
    }

    for(auto it=um.begin(); it!=um.end(); it++){
        ll cnt = it->second;
        ll event_cnt = cnt * (cnt-1) / 2;
        ans += event_cnt;
        // printf("%d ", cnt);
    }
    cout<<ans * 2;
    return 0;
}