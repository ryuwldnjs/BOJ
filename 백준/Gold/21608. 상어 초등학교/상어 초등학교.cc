#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
int n;
int m[25][25];

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<n;
}

pii getSurround(int y, int x, set<int>& likes){
    int like=0, empty=0;
    for(int i=0;i<4;i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(!pass(yy,xx)) continue;

        if(likes.count(m[yy][xx])) like++;
        else if(m[yy][xx] == 0) empty++;
    }

    return {like, empty};
}
void solve(int num, set<int>& likes){
    pii target={-1,-1};
    int MAX_like = -1;
    int MAX_empty = -1;

    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            if(m[y][x]) continue;
            auto [like, empty] = getSurround(y,x,likes);

            if(like > MAX_like){
                MAX_like = like;
                MAX_empty = empty;
                target = {y,x};
            }
            else if(like == MAX_like && empty > MAX_empty){
                MAX_empty = empty;
                target = {y,x};
            }
        }
    }

    m[target.first][target.second] = num;

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    vector<set<int>> likes_list(n*n+1);
    for(int i=0;i<n*n;i++){
        int num,a,b,c,d;
        cin>>num>>a>>b>>c>>d;
        set<int> likes = {a,b,c,d};
        likes_list[num] = likes;
        solve(num, likes);
    }


    int answer = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            auto [like, _] = getSurround(i,j,likes_list[m[i][j]]);
            int sum=1000;
            while(like++ < 4){
                sum /= 10;
            }
            answer += sum;
        }
    }
    cout<<answer;
    return 0;
}