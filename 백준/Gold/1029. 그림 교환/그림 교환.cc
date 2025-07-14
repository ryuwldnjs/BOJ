#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;
int answer = 0;
int n;
vector<vector<int>> graph;
vector<vector<int>> dp;
//dp[idx][bit] : bit조합으로 idx를 방문했을때의 최소 cost

void dfs(int now, int bit, int cost){
    int cnt = 0;
    for(int i=0;i<15;i++) if((1<<i)&bit) cnt++;
    answer = max(answer, cnt);
    dp[now][bit] = cost;

    for(int i=0;i<n;i++){
        if(bit & (1<<i)) continue;
        if(cost <= graph[now][i] && graph[now][i] < dp[i][bit | (1<<i)])
            dfs(i, bit | (1<<i), graph[now][i]);
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    graph.resize(n, vector<int>(n));
    dp.resize(n, vector<int>(1<<15, INF));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c; cin>>c;
            graph[i][j] = c - 0;
        }
    }

    dp[0][1] = 0;
    dfs(0, 1, 0);
    cout<<answer;
    return 0;
}