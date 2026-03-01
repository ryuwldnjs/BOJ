#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Key{
    int y,x;
    bool isDeleted;
};

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

bool pass(vector<vector<char>> &board, int y, int x){
    return 0<=y&&y<5 && 0<=x&&x<9 && board[y][x] != '#'; 
}

int dfs(vector<vector<char>> &board, vector<Key> &keys, int depth){
    int ret = depth;
     //현재 key가 옆 key를 없애고 점프
    for(auto &[y,x,isDeleted] : keys){
        if(isDeleted) continue;

        for(int i=0;i<4;i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            
            int yyy = y + 2*dy[i];
            int xxx = x + 2*dx[i];
            
            //키 이동
            if(pass(board, yy, xx) && pass(board, yyy, xxx) && board[yy][xx] != '.' && board[yyy][xxx] == '.'){
                int me = board[y][x];
                int next = board[yy][xx];
                int yi = y, xi = x;

                board[yi][xi] = board[yy][xx] = '.';
                board[yyy][xxx] = me;
                keys[next].isDeleted = true;
                y = yyy; x = xxx;

                ret = max(ret, dfs(board, keys, depth + 1));

                board[yi][xi] = me;
                board[yy][xx] = next;
                board[yyy][xxx] = '.';
                keys[next].isDeleted = false;
                y = yi; x = xi;
            }
        }
    }

    return ret;
}

void solve(){
    vector<vector<char>> board(5, vector<char>(9));
    vector<Key> keys;
    for(int i=0;i<5;i++){
        for(int j=0;j<9;j++){
            cin>>board[i][j];
            if(board[i][j] == 'o'){
                board[i][j] = keys.size();
                keys.push_back({i,j, false});
            }
        }
    }
    int cnt = dfs(board, keys, 0);

    cout<<keys.size() - cnt << ' ' << cnt<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}