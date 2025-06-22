#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int a[305][305];
int n,m,r;
bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m && a[y][x] != 0;
}

bool pass2(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m && a[y][x] == 0;
}

vector<int> scan(int sy, int sx){
    int dy = 0;
    int dx = 1;
    vector<int> ret;

    int y = sy;
    int x = sx;
    while(true){
        ret.push_back(a[y][x]);
        a[y][x] = 0;

        int yy = y + dy;
        int xx = x + dx;
        if(yy == sy && xx == sx) break;
        if(!pass(yy,xx)){
            int tmp = dy;
            dy = dx;
            dx = -tmp;
            yy = y + dy;
            xx = x + dx;
        }
        if(yy == sy && xx == sx) break;
        y = yy;
        x = xx;
    }
    return ret;
}

void draw(int sy, int sx, vector<int>& line){
    int dy = 0;
    int dx = 1;

    int y = sy;
    int x = sx;
    for(int val: line){
        a[y][x] = val;
        int yy = y + dy;
        int xx = x + dx;
        if(yy == sy && xx == sx) break;
        if(!pass2(yy,xx)){
            int tmp = dy;
            dy = dx;
            dx = -tmp;
            yy = y + dy;
            xx = x + dx;
        }
        if(yy == sy && xx == sx) break;
        y = yy;
        x = xx;
    }

}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m>>r;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    vector<vector<int>> lines;
    for(int i=0;i<min(n,m)/2;i++){
        vector<int> ret = scan(i,i);
        int idx = r % ret.size();
        rotate(ret.begin(), ret.begin() + idx, ret.end());        
        lines.push_back(ret);
    }


    for(int i=0;i<min(n,m)/2;i++){
        draw(i,i, lines[i]);
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}