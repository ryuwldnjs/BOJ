#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;

ll n;
vector<pll> increase, decrease, same;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(ll i=0;i<n;i++){
        ll a,b;cin>>a>>b;
        if(a < b) increase.push_back({a,b});
        else if(a > b) decrease.push_back({a,b});
        else same.push_back({a,b});
    }

    sort(increase.begin(), increase.end());
    sort(decrease.begin(), decrease.end(), [](pii& a, pii& b){
        // ll gap_a = a.first - a.second;
        // ll gap_b = b.first - b.second;
        // if(gap_a == gap_b) return a.first < b.first;
        // return gap_a < gap_b;
        // if(a.first == b.first) a.second > b.second;
        if(a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    });
    sort(same.begin(), same.end());

    ll answer = 0;
    ll free = 0;
    for(ll i=0;i<increase.size();i++){
        if(increase[i].first > free){
            answer += increase[i].first - free;//부족한 양만큼 주문
            free = increase[i].first;
        }
        free += increase[i].second - increase[i].first;

        // printf("%d\n",answer);
    }

    for(ll i=0;i<same.size();i++){
        if(same[i].first > free){
            answer += same[i].first - free;
            free = same[i].first;
        }
        // printf("%d\n",answer);

    }

    for(ll i=0;i<decrease.size();i++){
        if(decrease[i].first > free){
            answer += decrease[i].first - free;
            free = decrease[i].first;
        }
        free += decrease[i].second - decrease[i].first;//감소
        // printf("%d %d : %d %d\n",decrease[i].first, decrease[i].second, answer, free);

    }


    cout<<answer;
    return 0;
}