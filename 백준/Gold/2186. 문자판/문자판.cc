#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
vector<pii> pos[27];
vector<vector<int>> a;
int n,m,k;
int dp[105][105][85];

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m;
}
int solve(int y, int x, int idx, int target){
    int &ret = dp[y][x][idx-1];
    for(int i=0;i<4;i++){
        for(int j=1;j<=k;j++){
            int yy = y + dy[i] * j;
            int xx = x + dx[i] * j;
            if(!pass(yy,xx)) continue;
            if(a[yy][xx] == target) ret += dp[yy][xx][idx];
        }
    }
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m>>k;
    a.resize(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;cin>>c;
            a[i][j] = c - 'A';
            pos[c-'A'].push_back({i,j});
        }
    }

    string target; cin>>target;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) dp[i][j][target.size()-1] = 1;
    }

    for(int i=target.size()-1; i>=1 ;i--){
        int from = target[i-1] - 'A';
        int to = target[i] - 'A';

        for(int j=0;j<pos[from].size();j++){
            auto [y,x] = pos[from][j];
            solve(y, x, i, to);
        }
    }

    int answer = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            answer += dp[i][j][0];
        }
    }
    cout<<answer;
    return 0;
}