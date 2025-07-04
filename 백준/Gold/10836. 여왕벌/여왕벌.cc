#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int m,n;cin>>m>>n;
    vector<int> delta(2*m-1);
    vector<vector<int>>board(m, vector<int>(m,1));
    for(int i=0;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        delta[a]++;
        delta[a+b]++;
    }

    for(int i=1;i<2*m-1;i++){
        delta[i] += delta[i-1];
    }
    // for(int i=0;i<2*m-1;i++) cout<<delta[i]<<' ';
    // cout<<'\n';
    for(int i=0;i<m;i++){
        board[m-i-1][0] += delta[i];
    }
    for(int i=m;i<2*m-1;i++){
        board[0][i-m+1] += delta[i];
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<m;j++){
            board[i][j] = max({board[i-1][j], board[i-1][j-1], board[i][j-1]});
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}