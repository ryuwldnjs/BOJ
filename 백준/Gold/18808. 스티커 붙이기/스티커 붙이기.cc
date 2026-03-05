#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n,m;
int board[45][45];


bool canAttach(int y, int x, vector<vector<int>> &shape){
    for(int dy=0;dy<shape.size();dy++){
        for(int dx=0;dx<shape[dy].size();dx++){
            int yy = y + dy;
            int xx = x + dx;

            if(yy<0 || yy>=n || xx<0 || xx>=m || shape[dy][dx]==1&&board[yy][xx]==1) return false;
        }
    }
    return true;
}

int attach(int y, int x, vector<vector<int>> &shape){
    int ret = 0;

    for(int dy=0;dy<shape.size();dy++){
        for(int dx=0;dx<shape[dy].size();dx++){
            int yy = y + dy;
            int xx = x + dx;
            if(shape[dy][dx] == 1){
                // printf("%d ", board[yy][xx]);
                board[yy][xx] = 1;
                ret++;
            }
        }
    }
    return ret;
}

void rotate(vector<vector<int>> &shape){
    int r = shape.size();
    int c = shape[0].size();
    vector<vector<int>> tmp(c, vector<int>(r));

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int y = j;
            int x = r - i - 1;
            tmp[y][x] = shape[i][j];
        }
    }

    shape = tmp;
}

int solve(vector<vector<int>> &shape){

    for(int dir=0;dir<4;dir++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!canAttach(i, j, shape)) continue;
                return attach(i, j, shape);
            }
        }
        rotate(shape);
    }

    return 0;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int k; cin>>n>>m>>k;
    
    int answer = 0;
    for(int i=0;i<k;i++){
        int r,c;cin>>r>>c;
        vector<vector<int>> shape(r, vector<int>(c));
        for(int y=0;y<r;y++){
            for(int x=0;x<c;x++){
                cin>>shape[y][x];
            }
        }
        answer += solve(shape);
        // printf("%d\n", solve(shape));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         printf("%d ", board[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
    }

    cout<<answer;
    return 0;
}