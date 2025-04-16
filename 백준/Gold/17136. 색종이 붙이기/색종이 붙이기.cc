#include <iostream>
#include <vector>
using namespace std;
using pii=pair<int,int>;
const int n = 10;
const int INF = 20;
int map[n][n];


bool isOnes(int y, int x, int size){
    if(y+size > n || x+size > n) return false;
    for(int i=y;i<y+size;i++){
        for(int j=x;j<x+size;j++){
            if(map[i][j] == 0) return false;
        }
    }
    return true;
}
// pii OnesPosition(int size, int y, int x){
//     for(int i=y;i<n;i++){
//         int start_x = x;
//         if(i!=y) start_x = 0;
//         for(int j=start_x;j<n;j++){
//             if(isOnes(i,j,size)) return {i,j};
//         }
//     }
//     return {-1,-1};
// }

void setValue(int y, int x, int size, int value){
    for(int i=y;i<y+size;i++){
        for(int j=x;j<x+size;j++){
            map[i][j] = value;
        }
    }
}

int answer = INF;
int ones;
vector<int> remain(6, 5);

void solve(int used, int start_y, int start_x){
    // printf("%d %d %d\n", start_y, start_x, used);
    if(used >= answer) return;
    if(ones == 0){
        answer = min(answer, used);
        return;
    }

    for(int y=start_y; y<n; y++){
        if(y!=start_y) start_x = 0;

        for(int x=start_x; x<n; x++){
            
            if(map[y][x] == 0) continue;

            // i사이즈 색종이 놓을수 있을때
            for(int i=1;i<=5;i++){
                if(remain[i] == 0) continue;
                if(!isOnes(y, x, i)) break;

                setValue(y, x, i, 0);
                remain[i]--; ones -= i*i;
                
                solve(used+1, y , x+i);
                
                setValue(y, x, i, 1);
                remain[i]++; ones += i*i;
            }
            //현재 map[y][x]=1라면, 처리 못하고 넘어가는 경우는 없음
            return;
        }
    }
}


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
            if(map[i][j] == 1) ones++;
        }
    }

    solve(0, 0, 0);
    cout<<(answer==INF? -1 : answer);
    return 0;
}