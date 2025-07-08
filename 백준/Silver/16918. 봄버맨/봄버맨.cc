#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int dy[5] = {0,0,0,-1,1};
int dx[5] = {0,-1,1,0,0};
int r,c,n;
// int bomb[205][205];
vector<vector<int>> bomb;

bool pass(int y, int x){
    return 0<=y&&y<r && 0<=x&&x<c;
}
void play(int t){
    //폭탄설치
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(bomb[i][j] == -1) bomb[i][j] = t;
        }
    }
    vector<vector<int>> result = bomb;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(bomb[i][j] + 3 <= t){
                for(int dir=0;dir<5;dir++){
                    int ii = i + dy[dir];
                    int jj = j + dx[dir];
                    if(pass(ii,jj)) result[ii][jj] = -1;
                }
            }
        }
    }
    bomb = result;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>r>>c>>n;
    bomb.resize(r, vector<int>(c, -1));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            char x;cin>>x;
            if(x == 'O') bomb[i][j] = 0;
        }
    }

    for(int t=2;t<=n;t++){
        play(t);
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(bomb[i][j] == -1) cout<<'.';
            else cout<<'O';
        }
        cout<<'\n';
    }
    return 0;
}