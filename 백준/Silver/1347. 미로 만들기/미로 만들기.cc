#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define BIAS 50
#define INF 1e9
int r1,c1,r2,c2;
char board[BIAS + 55][BIAS + 55];

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    r1 = c1 = BIAS; 
    r2 = c2 = BIAS;
    int y = BIAS;
    int x = BIAS;
    int dy=1, dx=0;
    fill(&board[0][0], &board[BIAS + 54][BIAS + 54], '#');
    board[y][x] = '.';
    int n;cin>>n;


    for(int i=0;i<n;i++){
        char c; cin>>c;
        if(c == 'F'){
            y += dy;
            x += dx;
        }
        else if(c == 'R'){
            int tmp = dy;
            dy = dx;
            dx = -tmp;
        }
        else if(c == 'L'){
            int tmp = dy;
            dy = -dx;
            dx = tmp;
        }

        board[y][x] = '.';
        r1 = min(r1, y);
        c1 = min(c1, x);
        r2 = max(r2, y);
        c2 = max(c2, x);
    }


    for(int i=r1;i<=r2;i++){
        for(int j=c1;j<=c2;j++){
            cout<<board[i][j];
        }
        cout<<'\n';
    }
    return 0;
}