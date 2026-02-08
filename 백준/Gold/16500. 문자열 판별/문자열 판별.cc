#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

set<string> wordList;

int dp[105];
string s;
int n;

int solve(int idx){
    if(idx == -1) return 1;

    int &ret = dp[idx];
    if(ret != -1) return ret;

    for(int i=0;i<=idx;i++){
        string substr = s.substr(i, idx - i + 1);
        if(wordList.count(substr) && solve(i-1)) return ret = 1;
    }
    return ret = 0;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));

    cin>>s;
    cin>>n;
    for(int i=0;i<n;i++){
        string a; cin>>a;
        wordList.insert(a);
    }

    cout<<solve(s.size() - 1);
    return 0;
}