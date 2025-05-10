#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int y,x;
    int num;

    bool operator<(const Info &other)const{
        return num < other.num;
    }
};
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int n, k, s;
int m[205][205];

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<n;
}

void bfs(){
    queue<Info> q;
    vector<Info> init;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(m[i][j] != 0){
                init.push_back({i,j,m[i][j]});
                // q.push({i,j, m[i][j]});
            }
        }
    }

    sort(init.begin(), init.end());
    for(Info a: init){
        q.push(a);
    }
    int iteration = 0;
    while(!q.empty()){
        int sz = q.size();

        if(iteration == s){
            return;
        }
        
        for(int iter=0;iter<sz;iter++){
            int y = q.front().y;
            int x = q.front().x;
            int num = q.front().num;
            // printf("%d %d %d\n", y,x,num);
            q.pop();

            for(int i=0;i<4;i++){
                int yy = y + dy[i];
                int xx = x + dx[i];

                if(!pass(yy,xx)) continue;

                if(m[yy][xx] == 0){
                    q.push({yy,xx,num});
                    m[yy][xx] = num;
                }
            }



        }
        iteration++;




    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>m[i][j];
        }
    }
    int x,y;
    cin>>s>>x>>y;
    bfs();

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         printf("%d ", m[i][j]);
    //     }
    //     printf("\n");
    // }
    cout<<m[x-1][y-1];
    return 0;
}