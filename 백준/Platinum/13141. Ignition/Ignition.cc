#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;
struct Info{
    int a,b;
    double cost;
};

int n,m;
double answer = 1e9;
vector<Info> edges;
vector<vector<double>> dist;
void floyd(){
    for(int i=1;i<=n;i++) dist[i][i] = 0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
double findMinTime(int start){
    double MAX = -1;
    for(auto edge: edges){
        double a = dist[start][edge.a];
        double b = dist[start][edge.b];
        double cost = edge.cost;

        // abs(a-b) < cost, max(a,b) + max(0.0, cost - abs(a-b)) / 2        
        MAX = max(MAX, max(a,b) + max(0.0, cost - abs(a-b)) / 2);
    }
    return MAX;
}
int main(){
    cin>>n>>m;
    dist.resize(n+1, vector<double>(n+1, INF));
    for(int i=0;i<m;i++){
        int a,b;double c; cin>>a>>b>>c;

        edges.push_back({a,b,c});
        dist[a][b] = dist[b][a] = min(dist[a][b], c);
    }

    floyd();

    for(int i=1;i<=n;i++){
        answer = min(answer, findMinTime(i));
        // printf("%lf\n", answer);
    }
    printf("%.1lf", answer);
    return 0;
}