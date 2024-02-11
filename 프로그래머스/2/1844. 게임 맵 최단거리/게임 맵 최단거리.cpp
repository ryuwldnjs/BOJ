#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
queue<pii> q;
int n,m;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

bool pass(int x, int y, vector<vector<int>>&maps){
    return 0 <=x&&x< n && 0 <=y&&y< m && maps[x][y];
}

int solution(vector<vector<int> > maps){
    n = maps.size();
    m = maps[0].size();
    vector<vector<int>> dist(n, vector<int>(m));
    
    q.push({0,0});
    dist[0][0] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if(pass(xx, yy, maps) && maps[xx][yy] == 1){
                maps[xx][yy] = maps[x][y] + 1;
                q.push({xx,yy});
            }
        }
        
    }
    return maps[n-1][m-1] != 1 ? maps[n-1][m-1] : -1;
}