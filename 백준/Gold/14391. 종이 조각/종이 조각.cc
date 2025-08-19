#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n,m;
int board[4][4];
bool visited[4][4];

pii getNext(){
    pii ret = {-1,-1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]){
                ret = {i,j};
                return ret;
            }
        }
    }
    return ret;
}

int solve(int val){
    auto [y,x] = getNext();
    // printf("%d %d: %d\n", y,x,val);
    if(y == -1){
        return val;
    }

    int ret = val;
    int next_val=0;
    for(int i=y;i<=n;i++){
        if(i==n || visited[i][x]){
            for(int j=y;j<i;j++) visited[j][x] = false;
            break;
        }
        next_val = next_val*10 + board[i][x];
        // printf("%d %d: %d\n", y,x,next_val);
        visited[i][x] = true;
        ret = max(ret, solve(val + next_val));
    }
    // for(int i=y;i<n;i++) visited[i][x] = false;


    next_val = 0;
    for(int i=x;i<=m;i++){
        if(i==m || visited[y][i]){
            for(int j=x;j<i;j++) visited[y][j] = false;
            break;
        }
        next_val = next_val*10 + board[y][i];
        visited[y][i] = true;
        ret = max(ret, solve(val + next_val));
    }
    // for(int i=x;i<m;i++) visited[y][i] = false;

    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c; cin>>c;
            board[i][j] = c - '0';
        }
    }

    cout<<solve(0);
    return 0;
}