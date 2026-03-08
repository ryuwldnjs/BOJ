#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int dy[8] = {-1,-1,-1,0,0,1,1,1};
int dx[8] = {-1,0,1,-1,1,-1,0,1};

map<string, int> cnt;
char board[15][15];
int n,m,k;

void dfs(int y, int x, int depth, string &str){
    cnt[str]++;

    if(depth == 5){
        return;
    }

    for(int i=0;i<8;i++){
        int yy = (y + dy[i] + n) % n;
        int xx = (x + dx[i] + m) % m;
        str.push_back(board[yy][xx]);
        dfs(yy, xx, depth+1, str);
        str.pop_back();
    }
    return;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            string str; str.push_back(board[i][j]);
            dfs(i,j,1,str);
        }
    }

    for(int i=0;i<k;i++){
        string str;cin>>str;
        cout<<cnt[str]<<'\n';
    }
    return 0;
}