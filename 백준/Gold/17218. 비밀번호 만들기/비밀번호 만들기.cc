#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

string a,b;
int dp[45][45];

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>a>>b;
    a = " " + a;
    b = " " + b;

    for(int i=1;i<a.size();i++){
        for(int j=1;j<b.size();j++){
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
            dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
        }
    }
    
    int target = dp[a.size()-1][b.size()-1];

    string answer;
    int idxA = a.size()-1;
    int idxB = b.size()-1;
    while(target > 0){
        while(dp[idxA-1][idxB] == target) idxA--;
        while(dp[idxA][idxB-1] == target) idxB--;
        answer.push_back(a[idxA]);
        // printf("a[%d]:%c, b[%d]:%c\n", idxA, a[idxA], idxB, b[idxB]);
        idxA--; idxB--;
        target--;
    }
    reverse(answer.begin(), answer.end());

    cout<<answer;
    return 0;
}