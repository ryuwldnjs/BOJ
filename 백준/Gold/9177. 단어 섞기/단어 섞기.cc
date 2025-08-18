#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

string a,b,c;
int dp[205][205];
// [ax][bx] : a배열, b배열의 ax,bx인덱스 기준으로 c[ax+bx]배열을 만들수있는가
int recur(int idx1, int idx2){
    int idx3 = idx1 + idx2 + 1; // 0based 고려

    if(idx1 == 0 || idx2 == 0) return 1;
    if(a[idx1] != c[idx3] && b[idx2] != c[idx3]) return 0;

    
    int &ret = dp[idx1][idx2];
    if(ret != -1) return ret;


    if(a[idx1] == c[idx3]) ret = max(ret, recur(idx1-1, idx2));
    if(b[idx2] == c[idx3]) ret = max(ret, recur(idx1, idx2-1));


    return ret;
}

void solve(){
    cin>>a>>b>>c;
    a = "!" + a;
    b = "!" + b;
    c = "!!" + c;

    memset(dp, -1, sizeof(dp));

    if(recur(a.size()-1, b.size()-1)) cout<<"yes\n";
    else cout<<"no\n";

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Data set "<<i<<": ";
        solve();
    }
    return 0;
}