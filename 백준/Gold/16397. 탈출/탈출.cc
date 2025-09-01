#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n,t,g;
bool pass(int now){
    return now <= 99999;
}
int buttonB(int now){
    now *= 2;
    int tens=1;
    while(now / tens >= 10) tens*=10;
    now -= tens;
    return now;
}
void bfs(){
    queue<pii> q;
    vector<bool> visited(100000);
    visited[n] = true;
    q.push({n, 0});

    while(!q.empty()){
        int now = q.front().first;
        int cost = q.front().second;
        // printf("%d %d\n", now, cost);
        q.pop();
        if(cost > t) break;
        if(now == g){
            cout<<cost;
            return;
        }
        if(pass(now+1) && !visited[now+1]){
            visited[now+1] = true;
            q.push({now+1, cost+1});
        }

        if(now!=0 && pass(now*2) && !visited[buttonB(now)]){
            visited[buttonB(now)] = true;
            q.push({buttonB(now), cost+1});
        }
    }
    cout<<"ANG";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>t>>g;

    bfs();
    return 0;
}