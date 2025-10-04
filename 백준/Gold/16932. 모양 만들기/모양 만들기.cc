#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};


int n,m;
int board[1005][1005];
bool visited[1005][1005];

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m;
}
int dfs(int y, int x, int num){
    visited[y][x] = true;
    board[y][x] = num;
    
    int ret = 1;
    for(int i=0;i<4;i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(!pass(yy, xx)) continue;
        if(!visited[yy][xx] && board[yy][xx] == 1) ret += dfs(yy, xx, num);
    }
    return ret;
}

vector<int> cnt(1);//0은 더미
// cnt[i] : i번째 집단의 사이즈

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j] || board[i][j]==0) continue;
            cnt.push_back(dfs(i,j, cnt.size()));
        }
    }

    int answer = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==1) continue;

            set<int> nums;            
            for(int dir=0;dir<4;dir++){
                int yy = i + dy[dir];
                int xx = j + dx[dir];
                if(pass(yy,xx) && board[yy][xx]>0) nums.insert(board[yy][xx]);
            }

            int ret = 1;
            for(int num : nums){
                ret += cnt[num];
            }

            answer = max(answer, ret);

        }
        
    }

    
    cout<<answer;
    return 0;
}