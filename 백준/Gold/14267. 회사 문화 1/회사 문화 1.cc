#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;


int n,m;
vector<int> children[100000+5];
int totalScore[100000+5];

void dfs(int now, int score){
    totalScore[now] += score;

    for(int next: children[now]){
        dfs(next, totalScore[now]);
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int p;cin>>p; if(p==-1) continue;
        children[p].push_back(i);
    }

    for(int i=0;i<m;i++){
        int target, w;cin>>target>>w;
        totalScore[target] += w;
    }

    dfs(1, 0);

    for(int i=1;i<=n;i++){
        cout<<totalScore[i]<<' ';
    }
    return 0;
}