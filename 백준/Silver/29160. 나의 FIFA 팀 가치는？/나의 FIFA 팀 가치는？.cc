#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

priority_queue<int> pq[12];
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){
        int p,w;cin>>p>>w;
        pq[p].push(w);
    }

    while(k--){
        for(int i=1;i<=11;i++){
            if(pq[i].empty()) continue;
            int top = pq[i].top();
            pq[i].pop();
            if(top > 1) pq[i].push(top - 1);
        }
    }

    int answer = 0;
    for(int i=1;i<=11;i++){
        if(!pq[i].empty()) answer += pq[i].top();
    }
    cout<<answer;
    return 0;
}