#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;

void floyd(vector<vector<int>>&graph, int n){
    for(int i=1;i<=n;i++) graph[i][i] = 0;

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}
void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>> graph(n+1, vector<int>(n+1, INF));
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        graph[a][b] = c;
        graph[b][a] = c;
    }

    floyd(graph, n);

    int k;cin>>k;
    vector<int> friends(k);//친구들이 있는 곳
    for(int i=0;i<k;i++) cin>>friends[i];
    
    int MIN = INF;
    int answer = 1;
    
    for(int i=1;i<=n;i++){
        int sum = 0;
        for(auto pos: friends){
            sum += graph[pos][i];
        }

        if(sum < MIN){
            MIN = sum;
            answer = i;
        }

    }
    cout<<answer<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}