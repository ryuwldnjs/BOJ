#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int r,c,s;//r,c는 0 based
};
const int INF = 1e9;

int n,m,k;
vector<vector<int>> a;
vector<Info> command;

void rotate(vector<vector<int>> &tmp, int y, int x, int len){
    int dy = 1;
    int dx = 0;
    int init = tmp[y][x];
    for(int i=0;i<4;i++){
        for(int j=0;j<len;j++){
            if(i==3 && j==len-1) tmp[y][x] = init;
            else tmp[y][x] = tmp[y+dy][x+dx];
            y += dy;
            x += dx;
        }
        int tmp = dy;
        dy = -dx;
        dx = tmp;
    }
}

int solve(vector<int> &idx){
    vector<vector<int>> tmp = a;
    int ret = INF;
    for(int target: idx){
        auto [r,c,s] = command[target];
        for(int i=1;i<=s;i++) rotate(tmp, r-i, c-i, i*2);
    }

    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=0;j<m;j++){
            sum += tmp[i][j];
        }
        ret = min(ret, sum);
    }
    
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m>>k;
    a.resize(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    vector<int> idx;
    for(int i=0;i<k;i++) idx.push_back(i);
    
    while(k--){
        int r,c,s;cin>>r>>c>>s;
        r--;c--;
        command.push_back({r,c,s});
    }


    int answer = INF;
    do{
        answer = min(answer, solve(idx));
        // printf("%d ",answer);
    }while(next_permutation(idx.begin(), idx.end()));

    cout<<answer;    
    return 0;
}