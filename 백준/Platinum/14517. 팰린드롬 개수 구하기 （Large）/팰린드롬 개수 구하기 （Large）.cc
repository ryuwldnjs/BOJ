#include <iostream>
#include <string>
#include <vector>
#define MOD 10007
using namespace std;

// vector<vector<bool>> isPalindrome;//부분'문자열'이 팰린드롬인가
vector<vector<int>> dp; //부분'수열'의 팰린드롬의 개수
// dp[l][r]: dp[l][r-1] + dp[l+1][r] - dp[l+1][r-1] +(dp[l+1][r-1]+1)*(str[l]==str[r])

string str;
int solve(int l, int r){
    if(l==r) return 1;
    if(l > r) return 0;
    int& ret = dp[l][r];
    if(ret != -1) return ret;

    ret = solve(l, r-1) + solve(l+1, r) - solve(l+1, r-1);
    if(str[l] == str[r]) ret += solve(l+1, r-1) + 1;
    return ret = (ret + MOD) % MOD;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>str;
    int n = str.size();
    // isPalindrome.resize(n, vector<bool>(n, false));
    dp.resize(n, vector<int>(n, -1));

    cout<<solve(0, n-1);
    return 0;
}