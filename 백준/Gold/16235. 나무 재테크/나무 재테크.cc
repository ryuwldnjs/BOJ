#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int dy[8]={-1,-1,-1,0,0,1,1,1};
int dx[8]={-1,0,1,-1,1,-1,0,1};
int n,m,k;
vector<vector<int>> a, nutrient;
vector<vector<vector<int>>> tree;//[i][j]에 존재하는 나무의 레벨 리스트
bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<n;
}

void run(){
    vector<vector<vector<int>>> alive(n, vector<vector<int>>(n)),dead(n, vector<vector<int>>(n));
    //봄
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int iter = tree[i][j].size();
            sort(tree[i][j].begin(), tree[i][j].end());

            for(int age: tree[i][j]){
                if(nutrient[i][j] >= age){
                    nutrient[i][j] -= age;
                    alive[i][j].push_back(age+1);
                }
                else{
                    dead[i][j].push_back(age);
                }
            }
        }
    }
    tree = alive;

    //여름
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int age: dead[i][j]){
                nutrient[i][j] += age/2;
            }
        }
    }

    //가을
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            for(int age: tree[y][x]){
                if(age % 5 != 0) continue; //5의 배수일때만

                for(int dir=0;dir<8;dir++){
                    int yy = y + dy[dir];
                    int xx = x + dx[dir];
                    if(!pass(yy, xx)) continue;
                    tree[yy][xx].push_back(1);
                }
            }

        }
    }

    //겨울
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            nutrient[i][j] += a[i][j];
        }
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m>>k;
    a.resize(n, vector<int>(n));
    nutrient.resize(n, vector<int>(n, 5));
    tree.resize(n, vector<vector<int>>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    for(int i=0;i<m;i++){
        int x,y,z;cin>>x>>y>>z;
        x--;y--;
        tree[x][y].push_back(z);

    }

    while(k--) run();

    int answer = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            answer += tree[i][j].size();
        }
    }
    cout<<answer;
    return 0;
}