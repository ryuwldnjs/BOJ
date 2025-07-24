#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll MOD = 998244353;

ll n;
vector<ll> a,b;
vector<ll> a_idx,b_idx;
ll answer = 1;
void solve(int al, int ar, int bl, int br){
    // if(answer == 0) return;
    if(al == ar && bl==br) return;

    if(ar-al != br-bl || a[al] != b[br]){
        answer = 0;
        return;
    } 


    int rootL = a[al+1];
    int rootR = b[br-1];
    
    //단일 자식
    if(rootL == rootR){
        answer = (answer * 2) % MOD;
        solve(al+1, ar, bl, br-1);
    }
    else{
        solve(al+1, a_idx[rootR]-1, bl, b_idx[rootL]);
        solve(a_idx[rootR], ar, b_idx[rootL]+1, br-1);
    }

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    a.resize(n+1);
    b.resize(n+1);
    a_idx.resize(n+1);
    b_idx.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>a[i];
        a_idx[a[i]] = i;
    }

    for(int i=1;i<=n;i++){
        cin>>b[i];
        b_idx[b[i]] = i;
    }

    solve(1, n, 1, n);

    cout<<answer;
    return 0;
}