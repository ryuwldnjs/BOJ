#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

int n;
char board[10][10];
vector<pii> teachers, arr;
bool isAnswer;
// int students;

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<n && board[y][x] != 'O';
}

void process(){
    int catchS = 0;//잡은 학생 수
    // bool visited[10][10]={};

    for(pii teacher: teachers){
        auto [y,x] = teacher;
        // visited[y][x] = true;

        for(int i=0;i<4;i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            while(pass(yy,xx)){
                // visited[yy][xx] = true;
                if(board[yy][xx] == 'S') catchS++;
                yy += dy[i];
                xx += dx[i];
            }
        }
        // printf("%d,%d : %d\n", y,x,catchS);

    }
    if(catchS == 0) isAnswer = true;
}

void setWall(int idx, char c){
    board[arr[idx].first][arr[idx].second] = c;
}


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
            if(board[i][j] == 'T') teachers.push_back({i,j});
            if(board[i][j] == 'X') arr.push_back({i,j});
            // if(board[i][j] == 'S') students++;
            
        }
    }


    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            for(int k=j+1;k<arr.size();k++){
                setWall(i, 'O');
                setWall(j, 'O');
                setWall(k, 'O');

                process();

                setWall(i, 'X');
                setWall(j, 'X');
                setWall(k, 'X');

            }
        }
    }

    if(isAnswer) cout<<"YES";
    else cout<<"NO";
    return 0;
}