#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define MOD 10007

int dp[1005] = {1, };

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m,h; cin>>n>>m>>h;

    for(int i=0;i<n;i++){
        vector<int> nums;
        int num;
        while(cin>>num){
            nums.push_back(num);
            if(cin.get() == '\n') break;

        }

        for(int i=h;i>=0;i--){
            for(int num: nums){
                if(i-num >= 0) dp[i] += dp[i - num];
                dp[i] %= MOD;
            }
        }
        // for(int i=0;i<=h;i++){
        //     printf("%d ", dp[i]);
        // }
        // printf("\n");
    }


    cout<<dp[h];
    return 0;
}