#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

const int INF = 1e9;

int n,p;
int graph[20][20];
bool isRunning[20];

//bit조합에 idx발전소가 추가될때의 최소비용
int getCost(int bit, int idx){
    if(isRunning[idx]) return 0; //이미 켜져있는 발전소
    int ret = INF;
    for(int i=0;i<n;i++){
        if(bit & (1<<i)) ret = min(ret, graph[i][idx]);
    }
    return ret;
}

int dp[1<<20]; //dp[bit] : bit조합일때 최소 거리합
int solve(int bit){
    if(bit == 0) return 0;

    int &ret = dp[bit];
    if(ret != -1) return ret;
    ret = INF;

    for(int i=0;i<n;i++){
        if((bit & 1<<i) == 0) continue;
        int next_bit = bit ^ (1<<i);

        ret = min(ret, solve(next_bit) + getCost(next_bit, i));
    }
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    fill(&dp[0], &dp[1<<20 - 1], -1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    for(int i=0;i<n;i++){
        char c;cin>>c;
        if(c == 'Y') {
            isRunning[i] = true;
        }

    }
    cin>>p;

    int answer = INF;
    for(int bit = 0; bit<(1<<n);bit++){
        solve(bit);
        if(__builtin_popcount(bit) >= p) answer = min(answer, solve(bit));
    }
    if(answer == INF) cout<<-1;
    else cout<<answer;
    return 0;
}