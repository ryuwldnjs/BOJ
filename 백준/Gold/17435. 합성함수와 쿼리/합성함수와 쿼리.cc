#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
vector<vector<int>> f;
int query(int n, int x){
    for(int i=0;n;i++){
        if(n%2) x = f[x][i];
        n /= 2;
    }
    return x;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int m;cin>>m;
    f.resize(m+1, vector<int>(20, -1));
    for(int i=1;i<=m;i++){
        cin>>f[i][0];
    }
    for(int j=1;j<20;j++){
        for(int i=1;i<=m;i++){
            f[i][j] = f[f[i][j-1]][j-1];
        }
    }

    int q;cin>>q;
    while(q--){
        int n,x;cin>>n>>x;
        cout<<query(n,x)<<'\n';
    }
    return 0;
}