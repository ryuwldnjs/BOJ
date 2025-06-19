#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int a,b;
    int cost;
};
int s;
bool visited[5000][5000];
//cost[i][j]:i개가 화면에, j개가 클립보드에 있는 경우까지의 시간
void bfs(){
    queue<Info> q;
    q.push({1,0, 0});
    visited[1][0] = true;
    while(!q.empty()){
        int a = q.front().a;
        int b = q.front().b;
        int cost = q.front().cost;
        q.pop();
        if(a == s){
            cout<<cost;
            return;
        }


        if(!visited[a][a]){
            q.push({a, a, cost+1});
            visited[a][a] = true;
        }
        if(a+b < 5000 && !visited[a+b][b]){
            q.push({a+b, b, cost+1});
            visited[a+b][b] = true;
        }
        if(a>0 && !visited[a-1][b]){
            q.push({a-1, b, cost+1});
            visited[a-1][b] = true;
        }

    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>s;
    bfs();
    return 0;
}