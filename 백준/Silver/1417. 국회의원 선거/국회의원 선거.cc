#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> pq;
int n, dasom, ans;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        if(i==0) dasom = x;
        else pq.push(x);
    }

    while(!pq.empty() && dasom <= pq.top()){
        int now = pq.top();
        pq.pop();
        dasom++;
        pq.push(now-1);
        ans++;
    }
    cout<<ans;
    return 0;
}