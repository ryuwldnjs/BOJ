#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
vector<int> dp; //dp[i]:연속좌석 길이가 i일때의 경우의 수
int solve(int len){
    if(len <= 1) return 1;
    int &ret = dp[len];
    if(ret != -1) return ret;

    return ret = (solve(len-1) + solve(len - 2));
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m;cin>>n>>m;
    dp.resize(n+5, -1);

    int prev = 0;
    int answer = 1;
    for(int i=0;i<m;i++){
        int x;cin>>x;
        int gap = x - prev - 1;
        prev = x;
        answer *= solve(gap);
    }

    int gap = n - prev;
    answer *= solve(gap);
    cout<<answer;
    return 0;
}