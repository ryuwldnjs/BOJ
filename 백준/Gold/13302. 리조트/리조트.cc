#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;

int n,m;
bool dayoff[105];
int dp[105][50]; //1-based
//[day][coupon] : day일 시작이고, coupon만큼 있을때 최솟값
int solve(int day, int coupon){
    if(day > n) return 0;

    int &ret = dp[day][coupon];
    if(ret != INF) return ret;
    
    if(dayoff[day]) return ret = solve(day+1, coupon);

    ret = min(ret, solve(day+1, coupon) + 10000);
    ret = min(ret, solve(day+3, coupon+1) + 25000);
    ret = min(ret, solve(day+5, coupon+2) + 37000);
    if(coupon>=3) ret = min(ret, solve(day+1, coupon-3));
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    fill(&dp[0][0], &dp[104][49], INF);

    for(int i=0;i<m;i++){
        int x;cin>>x;
        dayoff[x] = true;
    }

    cout<<solve(1,0);
    return 0;
}