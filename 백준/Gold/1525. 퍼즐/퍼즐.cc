#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    ll m;
    int y;
    int x;
    int cnt;
};

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

unordered_map<ll, bool> visited;
ll answer_m = 123456780LL;

bool pass(int y, int x){
    return 0<=y&&y<3 && 0<=x&&x<3;
}

ll vvToll(vector<vector<int>> &m){
    ll ret = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ret *= 10;
            ret += m[i][j];
        }
    }
    return ret;
}

vector<vector<int>> llTovv(ll val){
    vector<vector<int>> m(3, vector<int>(3));
    for(int i=2;i>=0;i--){
        for(int j=2;j>=0;j--){
            m[i][j] = val % 10;
            val /= 10;
        }
    }
    return m;
}

void bfs(vector<vector<int>> &init, int y, int x){
    queue<Info> q;
    q.push({vvToll(init), y, x, 0});

    while(!q.empty()){
        ll m = q.front().m;
        vector<vector<int>> vvm = llTovv(m);
        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().cnt;
        q.pop();

        if(y==2 && x==2 && m == answer_m){
            cout<<cnt;
            return;
        }

        for(int i=0;i<4;i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(!pass(yy,xx)) continue;

            swap(vvm[yy][xx], vvm[y][x]);
            ll next_m = vvToll(vvm);
            if(!visited[next_m]){
                q.push({next_m, yy, xx, cnt+1});
                visited[next_m] = true;    
            }
            swap(vvm[yy][xx], vvm[y][x]);
        }
    }

    cout<<-1;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    vector<vector<int>> init(3, vector<int>(3));
    int y,x;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>init[i][j];
            if(init[i][j]==0){
                y=i;
                x=j;
            }
        }
    }
    bfs(init, y,x);
    return 0;
}