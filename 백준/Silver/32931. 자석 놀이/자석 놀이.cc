#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
ll n;
vector<vector<ll>> cards(200000+40, vector<ll>(2)), dp(200000+40, vector<ll>(2, (ll)-1e18));
int main(){
    cin>>n;
    for(int i=0;i<n;i++){ cin>>cards[i][0]; }
    for(int i=0;i<n;i++){ cin>>cards[i][1]; }
    dp[0][0] = max(cards[0][0], cards[0][0] + cards[0][1]);
    dp[0][1] = cards[0][0] + cards[0][1];
    for(int i=1;i<n;i++){
        dp[i][0] = max(dp[i][0], dp[i-1][0] + cards[i][0]);
        dp[i][0] = max(dp[i][0], dp[i-1][0] + cards[i][0] + cards[i][1]);
        dp[i][0] = max(dp[i][0], dp[i-1][1] + cards[i][0] + cards[i][1]);

        dp[i][1] = max(dp[i][1], dp[i-1][1] + cards[i][1]);
        dp[i][1] = max(dp[i][1], dp[i-1][0] + cards[i][0] + cards[i][1]);
        dp[i][1] = max(dp[i][1], dp[i-1][1] + cards[i][0] + cards[i][1]);
    }
    cout<<dp[n-1][1];
    return 0;
}