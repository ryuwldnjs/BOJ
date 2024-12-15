#include <iostream>
#include <string>
#define BIAS 5000
using namespace std;

int now_x = BIAS;
int now_y = BIAS;
int n,k;
int obstacle[10000][10000];
void move(int dx, int dy){
    int xx = now_x + dx;
    int yy = now_y + dy;
    if(obstacle[xx][yy] == 1) return;
    now_x = xx;
    now_y = yy;
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        obstacle[x + BIAS][y + BIAS] = 1;
    }
    string com; cin>>com;
    for(char x : com){
        if(x == 'U') move(0,1);
        else if(x == 'D') move(0,-1);
        else if(x == 'R') move(1,0);
        else if(x == 'L') move(-1,0);
    }
    cout<<now_x - BIAS<<' '<<now_y - BIAS;
    return 0;
}