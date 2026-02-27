#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define INF 1e9
#define SIZE 200

int dp[205][205];
void nCr(){
    for(int i=0;i<=SIZE;i++){
        dp[i][0] = dp[i][i] = 1;
        for(int j=1;j<i;j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            if(dp[i][j] > INF) dp[i][j] = INF;
        }
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    nCr();
    int n,m,k; cin>>n>>m>>k;
    
    int len = n + m;

    if(dp[len][m] < k){
        cout<<-1;
        return 0;
    }

    string answer;
    for(int i=0;i<len;i++){
        if(dp[n+m-1][m] >= k){ // a
            answer.push_back('a');
            n--;
        }
        else{
            answer.push_back('z');
            k -= dp[n+m-1][m];
            m--;
        }
    }

    cout<<answer;
    return 0;
}