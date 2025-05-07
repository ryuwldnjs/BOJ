#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

string a,b;
int dp[4005][4005];
int answer;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>a>>b;

    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            if(a[i] == b[j]) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1);
            answer = max(answer, dp[i+1][j+1]);
        }
    }
    cout<<answer;
    return 0;
}