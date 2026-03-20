#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
struct Info{
    ll id; //회원번호
    ll time; //누적 걸린시간
    ll counter; //할당된 카운터 

    bool operator>(const Info &other)const{
        if(time == other.time) return counter > other.counter;
        return time > other.time;
    }
};

priority_queue<Info, vector<Info>, greater<Info>> pq;
vector<Info> ret; //나간순서로 id저장

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n,k;cin>>n>>k;
    
    for(ll i=0;i<n;i++){
        ll id,w;cin>>id>>w;
        if(i < k){
            pq.push({id, w, i});
            continue;
        }

        auto target = pq.top(); pq.pop();
        ret.push_back({target.id, target.time, target.counter});
        pq.push({id, target.time + w, target.counter});
    }

    while(!pq.empty()){
        auto target = pq.top(); pq.pop();
        ret.push_back({target.id, target.time, target.counter});
    }

    sort(ret.begin(), ret.end(), [](Info a, Info b){
        if(a.time == b.time) return a.counter > b.counter;
        return a.time < b.time;
    });

    ll answer = 0;
    for(ll i=0;i<n;i++){
        answer += ret[i].id * (i+1);
    }

    cout<<answer;
    return 0;
}