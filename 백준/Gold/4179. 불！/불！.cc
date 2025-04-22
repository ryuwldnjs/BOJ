#include <bits/stdc++.h>
using namespace std;
struct Info{
    int y, x;
};
int dy[4] ={0,0,-1,1};
int dx[4] ={-1,1,0,0};

int r,c;
char m[1005][1005];
Info Jihoon;
vector<Info> fires;
bool isOut(int y, int x){
    return !(0<=y&&y<r && 0<=x&&x<c);
}
void bfs(){
    queue<Info> J, fire;
    int time = 0;
    J.push(Jihoon);
    for(Info x: fires){
        fire.push(x);
    }

    while(!J.empty() || !fire.empty()){
        time++;
        int J_sz = J.size();
        while(J_sz--){
            int y = J.front().y;
            int x = J.front().x;
            J.pop();
            // printf("%d %d\n", y,x);
            //지훈이가 불에 타버린 세계선
            if(m[y][x] == 'F') continue;


            for(int i=0;i<4;i++){
                int yy = y + dy[i];
                int xx = x + dx[i];
                if(isOut(yy,xx)){
                    cout<<time;
                    return;
                }
                if(m[yy][xx] == '.') {
                    J.push({yy,xx});
                    m[yy][xx] = 'J';
                }
            }
        }

        int fire_sz = fire.size();
        while(fire_sz--){
            int y = fire.front().y;
            int x = fire.front().x;
            fire.pop();

            for(int i=0;i<4;i++){
                int yy = y + dy[i];
                int xx = x + dx[i];
                if(isOut(yy,xx)) continue;
                if(m[yy][xx] == '.' || m[yy][xx] == 'J'){
                    fire.push({yy,xx});
                    m[yy][xx] = 'F';
                }
            }

        }
    }
    cout<<"IMPOSSIBLE";
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>m[i][j];
            if(m[i][j] == 'J') Jihoon = {i,j};
            if(m[i][j] =='F') fires.push_back({i,j});
        }
    }
    bfs();
    return 0;
}