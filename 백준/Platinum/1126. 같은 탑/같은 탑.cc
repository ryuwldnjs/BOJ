#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;
vector<vector<int>> dp;
vector<int> arr;

//idx블럭기준으로 차이가 diff일때의 높은 타워의 높이
int solve(int idx, int diff){
    if(idx == -1 && diff == 0) return 0;
    else if(idx == -1 || diff > 250000) return -INF;

    int &ret = dp[idx][diff];
    if(ret != -INF) return ret;


    //idx블럭 사용 안함
    ret = max(ret, solve(idx-1, diff));

    //idx블럭 사용
    //작은쪽에 쌓았다면
    ret = max(ret, solve(idx-1, diff + arr[idx]));
    //큰쪽에 쌓았다면
    if(diff - arr[idx] >= 0) ret = max(ret, solve(idx-1, diff - arr[idx]) + arr[idx]);
    else ret = max(ret, solve(idx-1, arr[idx] - diff) + diff);
    // printf("%d %d %d\n", idx, diff, dp[idx][diff]);

    return ret;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n; cin>>n;
    arr.resize(n);
    dp.resize(n, vector<int>(500000+5, -INF));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int answer = solve(n-1, 0);
    if(answer == 0) cout<<-1;
    else cout<<answer;
    // cout<<solve(n-1, 0);
    return 0;
}