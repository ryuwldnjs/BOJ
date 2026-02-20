#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define INF 1e9

struct Info{
    int a,b,cost;
    bool operator<(const Info& other)const{
        return cost < other.cost;
    }
};

int n;
int finalDist[25][25];
vector<Info> arr; //후보 경로군들

vector<vector<int>> floyd(vector<vector<int>> graph){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    return graph;
}

int solve(){
    int ret = 0;
    vector<vector<int>> graph(n, vector<int>(n, INF));
    for(int i=0;i<n;i++) graph[i][i] = 0;

    for(auto [a,b,cost] : arr){
        vector<vector<int>> dist = floyd(graph);
        if(dist[a][b] == cost) continue;
        if(dist[a][b] < cost) return -1;

        graph[a][b] = graph[b][a] = cost;
        // printf("%d %d %d\n", a+1,b+1,cost);
        ret += cost;
    }
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>finalDist[i][j];
            if(i>j) arr.push_back({i,j, finalDist[i][j]});
        }
    }

    sort(arr.begin(), arr.end());

    cout<<solve();
    return 0;
}