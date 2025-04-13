#include <iostream>
#include <vector>
using namespace std;
using pii=pair<int,int>;

int n,h;
vector<vector<int>> ladder;
vector<pii> arr;
bool answer = false;
bool canPlace(int y, int x){
    return ladder[y][x-1]==0 && ladder[y][x+1]==0;
}

bool isAnswer(){
    vector<int> pos(n+1);
    for(int i=1;i<=n;i++) pos[i] = i;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=n-1;j++){
            if(ladder[i][j]==1) swap(pos[j], pos[j+1]);
        }
    }

    for(int i=1;i<=n;i++){
        if(pos[i] != i) return false;
    }
    return true;
}

void solve(int y, int x, int loop){
    if(loop == 0){
        if(isAnswer()) answer = true;
        return;
    }
    if(x > n-1){
        y++;
        x = 1;
    }

    for(int i=y;i<=h;i++){
        int s_x = i==y ? x: 1;
        for(int j=s_x;j<=n-1;j++){
            if(i==y && j<x) continue;
            if(ladder[i][j]==0 && canPlace(i,j)){
                ladder[i][j] = 1;
                solve(i,j+1, loop-1);
                ladder[i][j] = 0;
            }
        }
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int m; cin>>n>>m>>h;
    ladder.resize(h+1, vector<int>(n+1));

    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        ladder[a][b] = 1;
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=n-1;j++){
            arr.push_back({i,j});
        }
    }

    
    for(int i=0; i<=3; i++){
        solve(1,1, i);
        if(answer){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}