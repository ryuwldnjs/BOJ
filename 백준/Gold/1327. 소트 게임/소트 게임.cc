#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
map<string, int> dist;

int n,k;
void bfs(string &now, string &goal){
    queue<string> q;
    dist[now] = 0;
    q.push(now);

    while(!q.empty()){
        string now = q.front();
        q.pop();
        if(now == goal){
            cout<<dist[now];
            return;
        }
        for(int i=0;i<n-k+1;i++){
            string next = now;
            reverse(next.begin()+i, next.begin()+i+k);

            if(dist.count(next) == 1) continue;
            dist[next] = dist[now] + 1;
            q.push(next);
        }
    }

    cout<<-1;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>k;
    int num = 0;
    string start;
    for(int i=0;i<n;i++){
        char c; cin>>c;
        start.push_back(c);
    }
    string goal = start;
    sort(goal.begin(), goal.end());
    bfs(start, goal);
    return 0;
}