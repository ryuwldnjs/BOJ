#include <iostream>
#include <vector>
using namespace std;

struct Shark{
    int speed, dir, size;  
};

vector<vector<int>> map,tmp;
vector<Shark> shark;
int r,c,m;
int answer;
void catchShark(int x){
    for(int y=1;y<=r;y++){
        if(map[y][x] != 0){
            int& target = map[y][x];
            // printf("%d: [%d,%d], %d점\n", target, y,x,shark[target].size);
            answer += shark[target].size;
            target = 0;
            break;
        }
    }
}

void updateMap(){
    tmp = vector<vector<int>>(r+1, vector<int>(c+1));
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(map[i][j] != 0){
                Shark& target = shark[map[i][j]];
                int next_y = i;
                int next_x = j;
                // if(target.dir==1||target.dir==2) target.speed %= 2*(r-2)+2;
                // if(target.dir==3||target.dir==4) target.speed %= 2*(c-2)+2;

                if(target.dir==1){
                    next_y -= target.speed;
                    if(next_y < 1) {next_y = 2-next_y; target.dir=2;}
                    if(next_y > r) {next_y = 2*r-next_y; target.dir=1;}
                }
                else if(target.dir==2){
                    next_y += target.speed;
                    if(next_y > r) {next_y = 2*r-next_y; target.dir=1;}
                    if(next_y < 1) {next_y = 2-next_y; target.dir=2;}
                }
                else if(target.dir==3){
                    next_x += target.speed;
                    if(next_x > c) {next_x = 2*c-next_x; target.dir=4;}
                    if(next_x < 1) {next_x = 2-next_x; target.dir=3;}
                }
                else if(target.dir==4){
                    next_x -= target.speed;
                    if(next_x < 1) {next_x = 2-next_x; target.dir=3;}
                    if(next_x > c) {next_x = 2*c-next_x; target.dir=4;}
                }

                //작은 상어들은 잡아먹힘
                if(tmp[next_y][next_x]!=0 && target.size < shark[tmp[next_y][next_x]].size) continue;
                
                tmp[next_y][next_x] = map[i][j];
            }
        }
    }

    //상어 이동 후 맵 갱신
    map = tmp;
}
int main(){
    cin>>r>>c>>m;
    map = vector<vector<int>>(r+1, vector<int>(c+1));
    shark.resize(m+1);
    for(int i=1;i<=m;i++){
        int y,x,s,d,z;
        cin>>y>>x>>s>>d>>z;
        map[y][x] = i;
        if(d==1||d==2) s %= 2*(r-2)+2;
        if(d==3||d==4) s %= 2*(c-2)+2;
        shark[i] = {s,d,z};
    }

    for(int x=1;x<=c;x++){
        catchShark(x);
        updateMap();
    }
    cout<<answer;
    return 0;
}