#include <iostream>
#include <vector>
#define CROSS_EVEN 10 //0,2,4,6 전파
#define CROSS_ODD 11 //1,3,5,7 전파
using namespace std;
using ll=long long;
struct Info{
    int m, s, d;
    int cnt;
    //질량,속력, 방향
    //해당 자리에 개수
};

int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={-1,-1,0,1,1,1,0,-1};
int n;
vector<vector<Info>> map;

//이동 및 결합
void move(){
    vector<Info> waiting[n+5][n+5];
    vector<vector<Info>> tmp(n+5,vector<Info>(n+5));

    //도착할 다음장소 대기열
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            if(!map[y][x].cnt) continue;
            Info target = map[y][x];

            if(target.d < 8){
                int yy = (y + target.s * dy[target.d] + n) % n;
                int xx = (x + target.s * dx[target.d] + n) % n;
                yy = (yy+n)%n; xx = (xx+n)%n;
                waiting[yy][xx].push_back(target);
            }
            else{
                int m = target.m / 5;
                int s = target.s / target.cnt;
                if(m == 0) continue;

                if(target.d == CROSS_EVEN){
                    for(int i=0;i<8;i+=2){
                        int yy = (y + s * dy[i] + n) % n;
                        int xx = (x + s * dx[i] + n) % n;
                        yy = (yy+n)%n; xx = (xx+n)%n;

                        waiting[yy][xx].push_back({m, s, i, 1});
                    }
                }
                else if(target.d == CROSS_ODD){
                    for(int i=1;i<8;i+=2){
                        int yy = (y + s * dy[i] + n) % n;
                        int xx = (x + s * dx[i] + n) % n;
                        yy = (yy+n)%n; xx = (xx+n)%n;

                        waiting[yy][xx].push_back({m, s, i, 1});
                    }
                }
            }


        }
    }

    //대기열 해소
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            int total_cnt=0;
            int total_m=0;
            int total_s=0;
            int direction=0; // 한개만 존재했을땐 기존 방향 그대로 써먹기 위함
            bool existEven = false;
            bool existOdd = false;

            for(Info target: waiting[y][x]){
                total_cnt++;
                total_m += target.m;
                total_s += target.s;
                direction = target.d;
                if(target.d%2 == 0) existEven = true;
                if(target.d%2 == 1) existOdd = true;
            }
            if(total_cnt == 0) continue;

            if(total_cnt == 1) tmp[y][x] = {total_m, total_s, direction, total_cnt};
            else if(existEven && existOdd) tmp[y][x] = {total_m, total_s, CROSS_ODD, total_cnt};
            else tmp[y][x] = {total_m, total_s, CROSS_EVEN, total_cnt};
            //방향이 true = 섞여있으니 1,3,5,7로 퍼져야함
            //방향이 false = 모두 짝 모두 혹이니 0,2,4,6으로 퍼져야함
        }
    }
    map = tmp;
}


int getAnswer(){
    int ret = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            Info target = map[i][j];
            if(target.d==CROSS_EVEN || target.d==CROSS_ODD) ret += target.m / 5 * 4;
            else ret += target.m;
            // printf("%d ", target.m);
        }
        // printf("\n");
    }
    return ret;
}
int main(){
    int MM,k;
    cin>>n>>MM>>k;
    map.resize(n+5, vector<Info>(n+5));
    for(int i=0;i<MM;i++){
        int r,c,m,s,d; cin>>r>>c>>m>>s>>d;
        r--; c--;
        map[r][c] = {m,s,d,1};
    }


    for(int i=0; i<k;i++){
        move();
        // spread();
    }

    cout<<getAnswer();
    return 0;
}