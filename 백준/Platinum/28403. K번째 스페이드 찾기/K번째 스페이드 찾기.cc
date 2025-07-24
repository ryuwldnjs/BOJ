#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int n;
vector<ll> psum;

//k번째 카드 찾기
int play(int k){
    int idx = 0;
    int cnt = 0;
    while(psum[idx] < k){
        int next_idx = idx + k - psum[idx];
        if(next_idx > n) break;
        cnt++;
        idx = next_idx;
    }
    return cnt;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    psum.resize(n+1);
    for(int i=1;i<=n;i++){
        char x;cin>>x;
        if(x == 'S') psum[i]++;
        psum[i] += psum[i-1];
    }

    for(int i=1;i<=n;i++){
        cout<<play(i)<<' ';
    }
    return 0;
}