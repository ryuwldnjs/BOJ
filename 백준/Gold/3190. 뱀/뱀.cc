#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int n,k;
bool apple[105][105], visited[105][105];
char command[10000+5];

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<n && !visited[y][x];
}
int solve(){
    int time = 0;
    int y = 0, x = 0;
    int dy = 0, dx = 1;

    deque<pii> snake;
    snake.push_front({0,0});
    visited[0][0] = true;

    while(true){
        time++; y += dy; x += dx;
        if(!pass(y, x)) break;
        snake.push_front({y,x});
        visited[y][x] = true;

        if(apple[y][x]) apple[y][x] = false; //사과 냠냠
        else{
            auto tail = snake.back();
            snake.pop_back();
            visited[tail.first][tail.second] = false;
        }
        
        if(command[time] == 'L') tie(dy, dx) = make_pair(-dx, dy);
        else if(command[time] == 'D') tie(dy, dx) = make_pair(dx, -dy);        
    }
    return time;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>k;
    for(int i=0;i<k;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        apple[a][b] = true;
    }
    int l;cin>>l;
    for(int i=0;i<l;i++){
        int t;char c;cin>>t>>c;
        command[t] = c;
    }

    cout<<solve();
    return 0;
}