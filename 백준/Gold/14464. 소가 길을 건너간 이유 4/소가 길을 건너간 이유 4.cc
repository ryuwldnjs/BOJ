#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int c,n;
vector<int> chicken;
vector<pii> cow;
struct cmp{
    bool operator()(pii a, pii b){
        if(a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    }
};

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>c>>n;
    chicken.resize(c);
    cow.resize(n);
    for(int i=0;i<c;i++){
        cin>>chicken[i];
    }
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        cow[i] = {a,b};
    }

    sort(chicken.begin(), chicken.end());
    sort(cow.begin(), cow.end());
    priority_queue<pii, vector<pii>, cmp> pq;
    int answer = 0;
    int a=0,b=0; //chicken, cow
    for(int i=0;i<c;i++){

        while(b < n && chicken[i] >= cow[b].first) pq.push(cow[b++]);
        // printf("%d개: ", pq.size());
        while(!pq.empty()){
            pii target = pq.top();pq.pop();
            if(target.first <= chicken[i] && chicken[i] <= target.second){
                answer++;
                // printf("%d %d %d\n", chicken[i], target.first, target.second);
                break;
            }
        }
    }
    

    cout<<answer;
    return 0;
}