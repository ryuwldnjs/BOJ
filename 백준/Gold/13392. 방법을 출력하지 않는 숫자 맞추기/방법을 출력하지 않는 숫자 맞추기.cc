#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n;
vector<vector<int>> dp;
vector<int> goal;

// 0000 -> new_b로 만들어가는 과정
int solve(int idx, int diff){
    if(idx == n) return 0;
    int &ret = dp[idx][diff];
    if(ret != -1) return ret;


    int now = diff % 10;

    //i이하 전부 증가
    int increase = (goal[idx] - now + 10) % 10 + solve(idx+1, (diff + goal[idx] - now + 10) % 10);
    //i만 감소
    int decrease = (now - goal[idx] + 10) % 10 + solve(idx+1, diff);


    return ret = min(increase, decrease);
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    string a,b;
    cin>>n>>a>>b;
    dp.resize(n+1, vector<int>(10, -1));

    for(int i=0;i<n;i++){
        b[i] = b[i] - a[i] + '0';
        if(b[i] < '0') b[i] += 10;
        goal.push_back(b[i] - '0');
    }
    cout<<solve(0, 0);
    return 0;
}