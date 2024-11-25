#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Info{
    int num, cost;
    const bool operator<(const Info& other) const{
        return cost>other.cost;
    }
};
int n,m, MAX, cnt;
vector<int> cost, isSolved;
vector<vector<Info>> graph;
priority_queue<Info> pq;

int main(){
    cin>>n>>m;
    cost.resize(n+1);
    isSolved.resize(n+1);
    graph.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>cost[i];
        pq.push({i, cost[i]});
    }
    int r; cin>>r;
    while(r--){
        int a,b,d; cin>>a>>b>>d;
        graph[a].push_back({b, d});
    }
    while(!pq.empty()){
        int now = pq.top().num;
        int now_cost = pq.top().cost;
        pq.pop();
        if(isSolved[now]) continue;
        isSolved[now] = 1;
        MAX = max(MAX, now_cost);
        // printf("%d,%d ", now,MAX);

        if(++cnt == m){
            cout<<MAX;
            return 0;
        }

        for(int i=0;i<graph[now].size(); i++){
            int next = graph[now][i].num;
            cost[next] -= graph[now][i].cost;
            // int next_cost = cost[next] - graph[now][i].cost;

            pq.push({next, cost[next]});

        }
    }
    return 0;
}