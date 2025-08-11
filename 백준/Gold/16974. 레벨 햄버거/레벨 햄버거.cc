#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

//레벨 i의 햄버거의 총 사이즈
ll len[55]={1};
ll dp[55]={1};
//level버거의 [1,r] 1based 구간의 패티 개수
ll solve(int level, ll r){
    if(r < 1) return 0;
    if(level == 0) return 1;
    ll ret = 0;

    
    if(r <= len[level]/2){
        //젤 앞 번 제외
        ret = solve(level-1, r-1);
    }
    if(r > len[level]/2){
        //중간에 낀 패티
        ret = dp[level-1] 
            +  1 
            + solve(level-1, r - len[level-1]-2);
    }

    // printf("%d, %d : %d\n",level, r,ret);
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    for(int i=1;i<=50;i++){
        len[i] = len[i-1] * 2 + 3;
        dp[i] = dp[i-1] * 2 + 1;
    }
    
    ll n,x;cin>>n>>x;
    cout<<solve(n, x);
    
    return 0;
}