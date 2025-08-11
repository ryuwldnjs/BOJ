#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int board[110][110];
int x[110], y[110];//색종이 위치

void draw(int x, int y){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            board[x + i][y + j] = 1;
        }
    }
}

int psum[110][110];
int getPsum(int x1, int y1, int x2, int y2){
    return psum[x2][y2] - psum[x1-1][y2] - psum[x2][y1-1] + psum[x1-1][y1-1];
}


int solve(int a, int b){
    int ret=0;
    
    for(int x1=0;x1<10;x1++){
        for(int y1=0;y1<10;y1++){
            for(int x2=0;x2<10;x2++){
                for(int y2=0;y2<10;y2++){
                    int a1 = x[a] + x1;
                    int b1 = y[a] + y1;
                    int a2 = x[b] + x2;
                    int b2 = y[b] + y2;
                    if(getPsum(a1, b1, a2, b2) == (a2-a1+1) * (b2-b1+1))
                        ret = max(ret, (a2-a1+1) * (b2-b1+1));
                }
            }
        }
    }
    return ret;
    // for(int i=0;i<10;i++){
    //     int x1 = x[a];
    //     int y1 = y[a] + i;
    //     for(int j=0;j<10;j++){
    //         int x2 = x[b] + 9;
    //         int y2 = y[b] + j;
            
    //         if(getPsum(x1, y1, x2, y2) == (x2-x1+1) * (y2-y1+1)) 
    //             ret = max(ret, getPsum(x1, y1, x2, y2));
    //     }
    // }
    // for(int i=0;i<10;i++){
    //     int x1 = x[a] + i;
    //     int y1 = y[a];
    //     for(int j=0;j<10;j++){
    //         int x2 = x[b] + j;
    //         int y2 = y[b] + 9;
            
    //         if(getPsum(x1, y1, x2, y2) == (x2-x1+1) * (y2-y1+1)) 
    //             ret = max(ret, getPsum(x1, y1, x2, y2));
    //     }
    // }
    // printf("%d %d: %d\n",a,b,ret);;
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
        assert(x[i] > 0);
        assert(y[i] > 0);
        draw(x[i], y[i]);
    }

    for(int i=1;i<=105;i++){
        for(int j=1;j<=105;j++){
            psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + board[i][j];
        }
    }

    int answer = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            answer = max(answer, solve(i,j));
        }
    }

    cout<<answer;

    return 0;
}