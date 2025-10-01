#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int psum[5000+5][5000+5];
int board[5000+5][5000+5];
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,r,c,w;cin>>n>>r>>c>>w;

    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        board[a][b] = 1;
    }

    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + board[i][j];
        }
    }

    int MAX = -1;
    int x,y;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(board[i][j] == 1) continue;
            
            int x1 = max(i - w/2, 1);
            int y1 = max(j - w/2, 1);
            int x2 = min(i + w/2, r);
            int y2 = min(j + w/2, c);

            int val = psum[x2][y2] - psum[x1-1][y2] - psum[x2][y1-1] + psum[x1-1][y1-1];
            if(val > MAX){
                MAX = val;
                x = i;
                y = j;
            }
        }
    }

    cout<<MAX<<'\n';
    cout<<x<<' '<<y;
    return 0;
}