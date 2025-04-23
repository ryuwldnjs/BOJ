#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
struct Info{
    int num, dir;
};

const pii NOT_EXIST = {-1,-1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int dx[8] = {0,-1,-1,-1,0,1,1,1};

bool pass(int y, int x){
    return 0<=y&&y<4 && 0<=x&&x<4;
}

pii findFish(vector<vector<Info>>&m, int num){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(m[i][j].num == num) return make_pair(i,j);
        }
    }
    return NOT_EXIST;
}
void move_fish(vector<vector<Info>>&m, pii shark){
    for(int num=1;num<=16;num++){
        pii target = findFish(m,num);
        if(target == NOT_EXIST) continue; //이미 잡아먹힌 물고기
        
        int y = target.first;
        int x = target.second;
        int dir = m[y][x].dir;

        for(int i=0;i<8;i++){
            int next_dir = (dir+i) % 8;
            int yy = y + dy[next_dir];
            int xx = x + dx[next_dir];
            if(!pass(yy,xx) || make_pair(yy,xx) == shark) continue;
            
            m[y][x].dir = next_dir;
            swap(m[y][x], m[yy][xx]);
            break;
        }

    }

}

int solve(vector<vector<Info>> m, pii shark){
    int ret = 0;
    int shark_dir = m[shark.first][shark.second].dir;

    move_fish(m, shark);

    //상어가 사냥 시작
    for(int i=1;i<=3;i++){
        auto tmp_m = m;
        int yy = shark.first + i * dy[shark_dir];
        int xx = shark.second + i * dx[shark_dir];
        //밖으로 넘어가거나, 물고기가 없으면
        if(!pass(yy,xx) || tmp_m[yy][xx].num == -1) continue;
        
        int target_num = tmp_m[yy][xx].num;
        pii next_shark = {yy,xx};
        tmp_m[yy][xx].num = -1;
        ret = max(ret, solve(tmp_m, next_shark) + target_num);

    }
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    vector<vector<Info>> m(4, vector<Info>(4));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int a,b;cin>>a>>b;
            b--; //방향은 0베이스로
            m[i][j] = {a,b};
        }
    }

    pii shark = {0,0};
    int answer = m[0][0].num;
    m[0][0].num = -1; //잡아 먹힌걸 의미

    answer += solve(m, shark);
    cout<<answer;
    return 0;
}