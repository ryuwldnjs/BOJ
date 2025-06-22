#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int init_x[4]={1,0,-1,0};
int init_y[4]={0,-1,0,1};
bool graph[105][105];
void makeDragon(int x, int y, int d, int g){
    vector<int> dx={init_x[d]}, dy={init_y[d]};

    while(g--){
        for(int i=dx.size()-1;i>=0;i--){
            dx.push_back(dy[i]);
            dy.push_back(-dx[i]);
        }
    }

    graph[y][x] = true;
    for(int i=0;i<dx.size();i++){
        x += dx[i];
        y += dy[i];
        graph[y][x] = true;
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    
    for(int i=0;i<n;i++){
        int x,y,d,g;cin>>x>>y>>d>>g;
        makeDragon(x, y, d, g);
    }

    int answer = 0;
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            if(graph[i][j] && graph[i+1][j] && graph[i][j+1] && graph[i+1][j+1])
                answer++;
        }
    }

    cout<<answer;
    return 0;
}