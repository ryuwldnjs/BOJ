#include <iostream>
#include <vector>
#include <string>
#define LEFT 6
#define RIGHT 2
using namespace std;
vector<string> wheel(5);
//dir방향으로 rotate할 target과 그 다음 진행 방향
void rotate(int now, int dir, int dx){
    //왼쪽 전파
    if(dx <= 0 && now > 1){
        if(wheel[now-1][RIGHT] != wheel[now][LEFT])
            rotate(now-1, -dir, -1);
    }
    //오른쪽 전파
    if(dx >= 0 && now < 4){
        if(wheel[now][RIGHT] != wheel[now+1][LEFT])
            rotate(now+1, -dir, 1);
    }

    //회전처리
    if(dir == 1){
        wheel[now] = wheel[now].back() + wheel[now].substr(0, 7);
    }
    else if(dir == -1){
        wheel[now] = wheel[now].substr(1) + wheel[now].front();
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    for(int i=1;i<=4;i++) cin>>wheel[i];
    int k; cin>>k;
    while(k--){
        int idx, dir; cin>>idx>>dir;
        rotate(idx, dir,0);
    }

    int answer = 0;
    for(int i=4;i>=1;i--){
        answer <<= 1;
        if(wheel[i][0] == '1') answer++;
    }
    cout<<answer;
    return 0;
}