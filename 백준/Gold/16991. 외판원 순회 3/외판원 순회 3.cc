#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<double,double>;
using pll=pair<ll,ll>;
#define INF 1e9

double dist[20][20];
double getDist(pii A, pii B){
    return sqrt((A.first - B.first)*(A.first - B.first) + (A.second - B.second)*(A.second - B.second));
}


int n;
double dp[1<<16][16];

double solve(int bit, int now){
    //모든 도시 방문
    if(bit == (1<<n)-1){
        return dist[now][0];
    }

    double &ret = dp[bit][now];
    if(ret != INF) return ret;

    for(int next=1;next<n;next++){
        if(bit & (1<<next)) continue; //이미 방문함

        ret = min(ret, solve(bit | (1<<next), next) + dist[now][next]);
    }

    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;

    pii a[20]={};
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        a[i] = {x,y};
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            dist[i][j] = dist[j][i] = getDist(a[i], a[j]);
        }
    }


    
    fill(&dp[0][0], &dp[(1<<16)-1][15]+1, INF);

    cout.precision(6);
    cout<<fixed<<solve(1, 0); //0번도시에서 시작

    return 0;
}