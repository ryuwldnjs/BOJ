#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
//dp[i][bit]:i번째 블럭에서 앞으로 4개의 블럭의 상태
//i이전까지는 채워져있음이 보장
//i+4칸부터는 비워져있음이 보장
vector<vector<int>> dp(1000*4, vector<int>(16, -1));
int f(int idx, int bit){
    if(idx == 1000*4 && bit == 0) return 1;
    if(idx >= 1000*4) return 0;

    int &ret = dp[idx][bit];
    if(ret != -1) return ret;
    ret = 0;

    //이미 다음칸이 채워져 있음
    if(bit & 1) ret += f(idx+1, bit>>1);
    else{
        //행 끝이 아니면서, 우측 한칸이 비어있을떄
        if(idx%4 != 3 && (bit & 2) == 0) ret += f(idx + 2, bit>>2);
        
        //세로 배치
        ret += f(idx+1, (bit>>1) | (1<<3));
    }
    return ret;
}
void solve(){
    int n;cin>>n;
    

    cout<<f((1000-n)*4, 0)<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    // f(0, 0);
    int t; cin>>t; while(t--) solve();
    return 0;
}