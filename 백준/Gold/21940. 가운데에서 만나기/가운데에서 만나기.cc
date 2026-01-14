#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define INF 1e9

int n,m;
int dist[205][205];

void floyd(){
    for(int i=1;i<=n;i++) dist[i][i] = 0;

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    fill(&dist[0][0], &dist[204][204], INF);

    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        dist[a][b] = c;
    }

    floyd();

    int k;cin>>k;
    vector<int> city(k);
    for(int i=0;i<k;i++){
        cin>>city[i];
    }

    int MIN=INF;
    vector<int> answer;
    //i로 모였을때 최대 소요 시간
    for(int i=1;i<=n;i++){
        int ret = -INF;
        for(auto c : city){
            ret = max(ret, dist[c][i] + dist[i][c]);
        }
        if(ret < MIN){
            MIN = ret;
            answer.clear();
        }
        if(ret == MIN){
            answer.push_back(i);
        }
    }

    sort(answer.begin(), answer.end());
    for(int i: answer) cout<<i<<' ';

    return 0;
}