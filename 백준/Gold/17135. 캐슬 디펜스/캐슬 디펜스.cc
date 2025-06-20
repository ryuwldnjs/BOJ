#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int n,m,d;
vector<vector<int>> enemy;
//궁수를 a,b,c에 각각 배치했을때
bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m;
}

int hunt(vector<vector<int>> &game, vector<vector<int>> &tmp, int x){
    //거리가 i인 적들부터 죽임
    for(int i=1;i<=d;i++){

        for(int dx = -i; dx <= i; dx++){
            int dy = i - abs(dx);
            
            int yy = n - dy;
            int xx = x + dx;
            if(pass(yy,xx) && game[yy][xx]==1){
                if(tmp[yy][xx]==1){
                    tmp[yy][xx] = 0;
                    return 1;
                }
                return 0;
            }
        }

    }
    return 0;
}

//턴종료 후 한칸씩 이동
void move(vector<vector<int>> &game){
    for(int i=n-1;i>0;i--){
        for(int j=0;j<m;j++){
            game[i][j] = game[i-1][j];
        }
    }
    for(int j=0;j<m;j++) game[0][j] = 0;
}


int solve(vector<int> &shooter){
    vector<vector<int>> game = enemy;
    int ret = 0;
    //한 턴
    for(int i=0;i<n;i++){
        vector<vector<int>> tmp = game;
        for(int j=0;j<shooter.size();j++){
            ret += hunt(game, tmp, shooter[j]);
        }
        game = tmp;
        move(game);
    }
    
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m>>d;
    enemy.resize(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>enemy[i][j];
        }
    }


    int answer = 0;
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            for(int k=j+1;k<m;k++){
                vector<int> shooter = {i,j,k};
                answer = max(answer, solve(shooter));
            }
        }
    }
    cout<<answer;
    return 0;
}