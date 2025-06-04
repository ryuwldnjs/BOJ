#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

int answer = INF;
int arr[105][105];
bool visited[105][105];
int n;

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<n;
}

//MAX-MIN차가 mid이하일때만 이동가능할때
bool dfs(int y, int x, int MIN, int MAX){
    if(arr[y][x] < MIN || arr[y][x] > MAX) return false;

    visited[y][x] = true;

    if(y == n-1 && x == n-1){
        return true;
    }
    
    for(int i=0;i<4;i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(!pass(yy, xx)) continue;

        if(!visited[yy][xx]){
            if(dfs(yy, xx, MIN, MAX)) return true;
        }
    }
    return false;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    int l=0,r=0;
    while(r <= 200){
        memset(visited, 0, sizeof(visited));
        if(dfs(0,0,l,r)){ 
            answer = min(answer, r-l);
            l++;
        }
        else r++;
    }
    cout<<answer;
    return 0;
}