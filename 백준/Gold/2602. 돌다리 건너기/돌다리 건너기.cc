#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

//[i][j][row] : i번째 두루마리, row행의 j번째 돌을 볼때, 경우의 수 
int dp[25][105][2];
string str,a,b;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>str;
    cin>>a>>b;

    for(int j=0;j<a.size();j++){
        if(str[0] == a[j]) dp[0][j][0] = 1;
        if(str[0] == b[j]) dp[0][j][1] = 1;
    }


    for(int i=1;i<str.size();i++){
        for(int j=0;j<a.size();j++){
            for(int k=0;k<j;k++){
                if(str[i] == a[j] && str[i-1] == b[k]) dp[i][j][0] += dp[i-1][k][1];
                if(str[i] == b[j] && str[i-1] == a[k]) dp[i][j][1] += dp[i-1][k][0];
            }
        }
    }

    int answer = 0;
    for(int j=0;j<a.size();j++){
        answer += dp[str.size()-1][j][0] + dp[str.size()-1][j][1];
    }

    cout<<answer;
    return 0;
}