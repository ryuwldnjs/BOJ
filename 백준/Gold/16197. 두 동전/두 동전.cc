#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii=pair<int,int>;
struct Info{
    int y1, x1; //1번 코인
    int y2, x2; // 2번 코인
};

int n,m;
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
char graph[25][25];

bool isOutOfBoard(int y, int x){
    return !(0<=y&&y<n && 0<=x&&x<m);
}

void bfs(Info start){
    queue<Info> q;

    q.push(start);
    int iterator = 0;
    while(!q.empty()){
        int sz = q.size();
        iterator++;
        if(iterator > 10) break;
        while(sz--){
            int y1 = q.front().y1;
            int x1 = q.front().x1;
            int y2 = q.front().y2;
            int x2 = q.front().x2;
            q.pop();

            
            for(int i=0;i<4;i++){
                int yy1 = y1 + dy[i];
                int xx1 = x1 + dx[i];
                int yy2 = y2 + dy[i];
                int xx2 = x2 + dx[i];

                //벽이면 못움직임
                if(graph[yy1][xx1] == '#'){
                    yy1 = y1;
                    xx1 = x1;
                }
                if(graph[yy2][xx2] == '#'){
                    yy2 = y2;
                    xx2 = x2;
                }

                //둘중 하나만 탈출 했다면?
                if(isOutOfBoard(yy1, xx1) ^ isOutOfBoard(yy2, xx2)){
                    cout<<iterator;
                    return;
                }
                //둘다 동시에 탈출?
                if(isOutOfBoard(yy1, xx1) && isOutOfBoard(yy2, xx2)){
                    continue;
                }
                q.push({yy1, xx1, yy2, xx2});
            }
        }

    }

    cout<<-1;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    vector<pii> coin;

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0; j<m; j++){
            cin>>graph[i][j];
            if(graph[i][j] == 'o'){
                coin.push_back({i,j});
                graph[i][j] = '.';
            }
        }
    }


    bfs({coin[0].first, coin[0].second, coin[1].first, coin[1].second});
    return 0;
}