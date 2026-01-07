#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int y,x;
};

char board[1005][1005];
int surround[1005][1005];
int h,w;
queue<Info> q;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>board[i][j];
        }
    }

    for(int i=1;i<h-1;i++){
        for(int j=1;j<w-1;j++){
            for(int dy=-1;dy<=1;dy++){
                for(int dx=-1;dx<=1;dx++){
                    int yy = i + dy;
                    int xx = j + dx;
                    if(board[yy][xx] == '.') surround[i][j]++;
                }
            }
            if(board[i][j] != '.' && (board[i][j]-'0' <= surround[i][j])) q.push({i,j});
        }
    }

    int answer = 0;
    while(!q.empty()){
        int sz = q.size();
        for(int i=0;i<sz;i++){
            auto [y,x] = q.front(); q.pop();

            for(int dy=-1;dy<=1;dy++){
                for(int dx=-1;dx<=1;dx++){
                    int yy = y + dy;
                    int xx = x + dx;
                    surround[yy][xx]++;
                    if(board[yy][xx] != '.' && (board[yy][xx]-'0' == surround[yy][xx]))
                        q.push({yy,xx});
                }
            }

        }
        answer++;
    }

    cout<<answer;
    return 0;
}