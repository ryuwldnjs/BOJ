#include <iostream>
#include <vector>
#include <queue>
#define INF 2000000000
using namespace std;
using ll=long long;
struct Info{
    ll val, idx;
    bool operator<(const Info& other)const{
        if(val == other.val) return idx > other.idx;
        return val < other.val;
    }
    bool operator==(const Info& other)const{
        return val==other.val && idx==other.idx;
    }
};

ll n,d;
ll answer=-INF;
priority_queue<Info> all, deleted;
vector<ll> dp,arr;
/**
 * 슬라이딩윈도우에서 dp최댓값찾아서 dp 만들기
 */
int main(){
    cin>>n>>d;
    arr.resize(n+1);
    dp.resize(n+1);
    deleted.push({-INF, -1});

    for(ll i=0;i<n;i++){
        cin>>arr[i];
        dp[i] = arr[i];
    }

    for(ll i=0;i<n;i++){
        ll target = all.empty() ? -1 : all.top().idx;
        if(target != -1) dp[i] = max(dp[i], dp[target] + arr[i]);

        all.push({dp[i], i});
        if(i-d>=0) deleted.push({dp[i-d], i-d});

        while(all.top() == deleted.top()){
            all.pop();
            deleted.pop();
        }  
        // printf("%d:%d, %d\n", i, target, dp[i]);
        answer = max(answer, dp[i]);
    }

    cout<<answer;
    return 0;
}