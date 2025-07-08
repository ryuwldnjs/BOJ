#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int dp[1000000];
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int pizza;cin>>pizza;
    int n,m;cin>>n>>m;
    vector<int> a(n*2), b(m*2);
    int total_a=0, total_b=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i+n] = a[i];
        total_a += a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
        b[i+m] = b[i];
        total_b += b[i];
    }
    dp[0]++;
    dp[total_a]++;

    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=0;j<n-1;j++){
            sum += a[i+j];
            dp[sum]++;
        }
    }

    int answer = dp[pizza];
    if(pizza - total_b >= 0) answer += dp[pizza - total_b];
    for(int i=0;i<m;i++){
        int sum = 0;
        for(int j=0;j<m-1;j++){
            sum += b[i+j];
            if(pizza - sum >= 0) answer += dp[pizza - sum];
        }
    }



    cout<<answer;
    return 0;
}