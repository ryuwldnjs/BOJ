#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n, answer;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        pq.push(x);
    }

    while(pq.size() >= 2){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        answer++;
        a--; b--;
        if(a > 0) pq.push(a);
        if(b > 0) pq.push(b);
    }

    if(pq.size()) answer += pq.top();

    if(answer > 1440) cout<<-1;
    else cout<<answer;
    return 0;
}