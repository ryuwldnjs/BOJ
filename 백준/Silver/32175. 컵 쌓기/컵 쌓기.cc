#include <iostream>
#include <vector>
#define MOD (ll)1000000007
using namespace std;
using ll=long long;
ll n,h;
vector<ll> a, dp;
int main(){
    cin>>n>>h;
    a.resize(n);
    dp.resize(100000+5);
    for(int i=0;i<n;i++){
        cin>>a[i];
        dp[a[i]]++;
    }


    for(ll level=0;level<=h;level++){
        for(int j=0;j<a.size();j++){
            if(level - a[j] < 0) continue;
            dp[level] += dp[level - a[j]];
            dp[level] %= MOD;
        }
    }
    cout<<dp[h];
    return 0;
}