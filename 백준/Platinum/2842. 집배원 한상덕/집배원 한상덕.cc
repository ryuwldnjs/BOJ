#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int dy[8] = {-1,-1,-1,0,0,1,1,1};
int dx[8] = {-1,0,1,-1,1,-1,0,1};
const int INF = 1e9;
set<int> s;

int n, k;
int convert[1000000+5];
int original[2500+5];
//좌표압축
void compress(){
    memset(convert, -1, sizeof(convert));
    memset(original, -1, sizeof(original));
    vector<int> arr(s.begin(), s.end());

    for(int i=0;i<arr.size();i++){
        convert[arr[i]] = i;
        original[i] = arr[i];
    }
}

void convertArr(int arr[55][55]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = convert[arr[i][j]];
        }
    }
}

char board[55][55];
int height[55][55];

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<n;
}


struct Info{
    int y,x;
    int cost;
    bool operator<(const Info &other)const{
        return cost < other.cost;
    }
};

//최대 hi이하 & 다닐때 모든 집을 다 방문했을때의 최소비용의 최댓값
int bfs(int sy, int sx, int hi){
    if(height[sy][sx] > hi) return -INF; //우체국도 불가능할떄

    int lo = hi;
    int cnt = 0; //발견한 집의 개수

    bool visited[55][55] = {};
    visited[sy][sx] = true;

    priority_queue<Info> pq;
    pq.push({sy, sx, height[sy][sx]});

    while(!pq.empty()){
        auto [y,x,cost] = pq.top();
        pq.pop();
        lo = min(lo, cost);
        if(board[y][x] == 'K') cnt++;
        if(cnt == k) return lo; //모든 집 방문 완료


        for(int i=0;i<8;i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(!pass(yy, xx)) continue;
            if(!visited[yy][xx] && height[yy][xx] <= hi){
                visited[yy][xx] = true;
                pq.push({yy, xx, height[yy][xx]});
            }
        }

    }

    //모든 집 방문 X
    return -INF;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    int sy,sx;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
            if(board[i][j] == 'P'){
                sy = i;
                sx = j;
            }
            if(board[i][j] == 'K') k++;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>height[i][j];
            s.insert(height[i][j]);
        }
    }

    compress();
    convertArr(height);

    int answer = INF;
    for(int i=0;i<=2500;i++){
        int val = bfs(sy, sx, i);
        if(original[i] == -1 || val == -INF) continue;

        int hi = original[i];
        int lo = original[val];

        answer = min(answer, hi - lo);
    }


    cout<<answer;
    return 0;
}