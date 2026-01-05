#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<vector<int>> lines;
int n,m,r;
int a[305][305];

vector<int> makeLine(int y, int x){
    vector<int> line;
    int dy=0, dx=1;

    line.push_back(a[y][x]);
    for(int i=0;i<4;i++){
        while(true){
            int yy = y + dy;
            int xx = x + dx;
            if(a[yy][xx] <= 0){
                int tmp = dy;
                dy = dx;
                dx = -tmp;
                break;
            }
            a[y][x] = 0;
            y = yy;
            x = xx;
            line.push_back(a[y][x]);

        }
    }
    a[y][x] = 0;
    return line;
}

void drawLine(int y, int x, vector<int> &line){
    int dy = 0, dx = 1;
    for(int i=0;i<line.size();i++){
        a[y][x] = line[i];

        if(a[y + dy][x + dx] != 0){
            int tmp = dy;
            dy = dx;
            dx = -tmp;
        }
        y = y + dy;
        x = x + dx;
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m>>r;

    memset(a, -1, sizeof(a));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    for(int i=1;i<=min(n,m)/2;i++){
        lines.push_back(makeLine(i, i));
    }

    for(int i=0;i<lines.size();i++){
        int mid = (r) % lines[i].size(); 
        rotate(lines[i].begin(), lines[i].begin() + mid, lines[i].end());
        // for(auto x : lines[i]) printf("%d ", x);
        // printf("\n");
    }



    for(int i=1;i<=min(n,m)/2;i++){
        drawLine(i,i, lines[i-1]);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}