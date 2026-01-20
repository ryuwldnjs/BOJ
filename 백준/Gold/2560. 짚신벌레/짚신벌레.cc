#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
#define MOD 1000LL
struct Info{
    ll birth;
    ll cnt;

    bool operator<(const Info& other)const{
        return birth > other.birth;
    }
};

ll duration[3], N;
priority_queue<Info> pq[3];
ll cnt[3]; //각 상태별총 개체 수

void solve(ll day){
    
    for(ll i=0;i<3;i++){
        if(pq[i].empty()) continue;
        Info top = pq[i].top();
        if(day - top.birth >= duration[i]){
            pq[i].pop();
            cnt[i] -= top.cnt;
            cnt[i] = (cnt[i] + MOD) % MOD;
            if(i<2) {
                pq[i+1].push(top);
                cnt[i+1] += top.cnt;
                cnt[i+1] = (cnt[i+1] + MOD) % MOD;
            }
        }
    }

    //성체 번식
    if(!pq[1].empty()) {
        pq[0].push({day, cnt[1]});
        cnt[0] += cnt[1];
        cnt[0] = (cnt[0] + MOD) % MOD;
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>duration[0]>>duration[1]>>duration[2]>>N;

    pq[0].push({0, 1});
    cnt[0] = 1;

    for(ll i=1;i<=N;i++){
        solve(i);
    }

    ll ret = (cnt[0] + cnt[1] + cnt[2]) % 1000LL;

    cout<<ret;
    return 0;
}