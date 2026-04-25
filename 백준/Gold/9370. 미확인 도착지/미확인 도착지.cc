#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9
using namespace std;
struct Info{
    int b, cost;
    bool operator<(const Info &other)const{
        return cost > other.cost;
    }
};
vector<vector<Info>> graph;

void dijkstra(int start, vector<int> &dist){
    priority_queue<Info> pq;

    dist[start] = 0;
    pq.push({start, 0});

    while(!pq.empty()){
        int now = pq.top().b;
        int now_distance = pq.top().cost;
        pq.pop();
        if(now_distance < dist[now]) continue;
        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].b;
            int next_distance = now_distance + graph[now][i].cost;
            if(next_distance < dist[next]){
                pq.push({next, next_distance});
                dist[next] = next_distance;
            }
        }
    }

}
void solve(){
    int n,m,t; cin>>n>>m>>t;
    int s,g,h; cin>>s>>g>>h;
    graph = vector<vector<Info>>(n+1);
    vector<int> dist_start, dist_g, dist_h;
    vector<int> dest; //목적지
    dist_start = dist_g = dist_h = vector<int>(n+1, INF);
    int dist_g_h;

    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
        if(a==g&&b==h || a==h&&b==g) dist_g_h = c;
    }

    for(int i=0;i<t;i++){
        int x; cin>>x;
        dest.push_back(x);
    }


    dijkstra(s, dist_start);
    dijkstra(g, dist_g);
    dijkstra(h, dist_h);

    vector<int> answer;
    int MIN = INF;


    for(int destination: dest){
        int MIN = min(dist_start[g] + dist_g_h + dist_h[destination], dist_start[h] + dist_g_h + dist_g[destination]);
        if(dist_start[destination] == MIN) answer.push_back(destination);
    }
    // //s -> g - > h -> dest
    // // dist_start[g] + dist_g_h;
    // for(int destination: dest){
    //     if(dist_start[g] + dist_g_h + dist_h[destination] <= MIN){
    //         if(dist_start[g] + dist_g_h + dist_h[destination] < MIN) answer = vector<int>();
    //         MIN = dist_start[g] + dist_g_h + dist_h[destination];
            
    //         answer.push_back(destination);
    //     }
    // }

    // //s -> h -> g -> dest
    // // dist_start[h] + dist_g_h;
    // for(int destination: dest){
    //     if(dist_start[h] + dist_g_h + dist_g[destination] <= MIN){
    //         if(dist_start[h] + dist_g_h + dist_g[destination] < MIN) answer = vector<int>();
    //         MIN = dist_start[h] + dist_g_h + dist_g[destination];
            
    //         answer.push_back(destination);
    //     }
    // }
    sort(answer.begin(), answer.end());
    for(int i: answer) cout<<i<<' ';
    cout<<'\n';
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}