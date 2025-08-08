#include <bits/stdc++.h>
#define MAX 500000
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int x;
    int cost;
};

int n,k;

bool pass(int x){
    return 0<=x&&x<=MAX;
}
void bfs(){
    queue<Info> q;
    vector<vector<int>> time(MAX+1, vector<int>(2, -1));
    q.push({n, 0});
    time[n][0] = 0;
    while(!q.empty()){
        auto [x, cost] = q.front();
        q.pop();
        vector<int> NEXT = {x-1, x+1, x*2};
        for(int next: NEXT){
            int next_cost = cost + 1;
            if(!pass(next)) continue;
            
            if(time[next][next_cost % 2] == -1){
                time[next][next_cost % 2] = next_cost;
                q.push({next, next_cost});
            }
        }
    }

    int answer = -1;
    for(int t=0;t<=1000;t++){
        int x = k + t*(t+1)/2;//t초 후 동생의 위치
        if(x > MAX) break;
        if(time[x][t%2] == -1 || time[x][t%2] > t) continue;
        answer = t;
        break;
    }

    cout<<answer;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>k;

    bfs();
    return 0;
}