#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int getNum(int sy, int sx){
    int line = max(abs(sy), abs(sx));
    
    int y = line, x = line;
    int dy = 0, dx = -1;
    int num = (line*2+1) * (line*2+1);

    while(!(y==sy && x==sx)){
        int yy = y + dy;
        int xx = x + dx;
        
        //지정된 테두리를 넘어설때
        if(max(abs(yy),abs(xx)) != line){
            int tmp = dy;
            dy = dx;
            dx = -tmp;
            continue;
        }
        num--;
        y = yy;
        x = xx;
    }
    return num;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;

    vector<vector<int>> answer;

    int MAX = 0;
    for(int i=r1;i<=r2;i++){
        vector<int> tmp;
        for(int j=c1;j<=c2;j++){
            tmp.push_back(getNum(i,j));
            MAX = max(MAX, tmp.back());
        }
        answer.push_back(tmp);
    }


    int len = to_string(MAX).size();

    for(int i=0;i<answer.size();i++){
        for(int j=0;j<answer[i].size();j++){
            cout<< setw(len) <<answer[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}