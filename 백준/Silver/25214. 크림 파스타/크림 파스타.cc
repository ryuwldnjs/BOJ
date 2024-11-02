#include <iostream>
using namespace std;

int dp[200000+5], n, MIN=1e9;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        MIN = min(MIN, x);
        dp[i] = max(dp[i-1], x - MIN);
        cout<<dp[i]<<' ';
 
    }
    return 0;
}