#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int n,m;
int board[10][10];

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m;
}
bool isSquare(int num){
    int root = sqrt(num);
    return root*root == num;
}

int solve(int y, int x, int dy, int dx){
    int ret = -1;
    int num = 0;

    while(pass(y, x)){
        num = num*10 + board[y][x];
        if(isSquare(num)) ret = max(ret, num);

        y += dy;
        x += dx;
    }
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;cin>>c;
            board[i][j] = c - '0';
        }
    }

    int answer = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int di=-n;di<n;di++){
                for(int dj=-m;dj<m;dj++){
                    if(di==0 && dj==0) continue;
                    answer = max(answer, solve(i,j,di,dj));
                }
            }
        }
    }

    cout<<answer;
    return 0;
}