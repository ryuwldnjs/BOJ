#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n;
int cost[15][15];

void floyd(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int k;cin>>n>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
        }
    }
    floyd();

    vector<int> order;
    for(int i=0;i<n;i++){
        if(i != k) order.push_back(i);
    }


    int answer = 1e9;
    do{
        int ret = cost[k][order.front()];
        for(int i=1;i<order.size();i++){
            ret += cost[order[i-1]][order[i]];
        }
        answer = min(answer, ret);
    }while(next_permutation(order.begin(), order.end()));

    cout<<answer;
    return 0;
}