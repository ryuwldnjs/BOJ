#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int n;
void turnRow(vector<vector<int>> &board, int r){
    for(int i=0;i<n;i++) board[r][i] = !board[r][i];
}
// void turnCol(vector<vector<int>> &board, int c){
//     for(int i=0;i<n;i++) board[i][c] = !board[i][c];
// }

//미리 뒤집어야할 행들을 정해둘때
int solve(vector<vector<int>> board, int bit){
    int ret = 0;
    for(int i=0;i<n;i++){
        if(bit & (1<<i)) turnRow(board, i);
    }

    //뒤집었을때 이득이 되는 열만 뒤집기
    for(int j=0;j<n;j++){
        int t=0;
        for(int i=0;i<n;i++) if(board[i][j] == 1) t++;
        ret += min(t, n - t); //뒤집혔거나 그대로거나
    }
    return ret;
}

vector<vector<int>> board;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    board.resize(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;cin>>c;
            if(c == 'H') board[i][j] = 0;
            else board[i][j] = 1; //T
        }
    }

    int answer = 1e9;
    for(int bit=0;bit<(1<<n);bit++){
        answer = min(answer, solve(board, bit));
    }

    cout<<answer;
    return 0;
}