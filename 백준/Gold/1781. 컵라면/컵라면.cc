#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<pii> arr;
priority_queue<int> pq;
const int LAST_DAY = 200000;
int n;
int solve(){
    int answer = 0;
    int idx = 0;
    sort(arr.begin(), arr.end(), greater<pii>());

    for(int day=LAST_DAY; day>=1; day--){
        while(idx<n && arr[idx].first >= day)
            pq.push(arr[idx++].second);

        if(pq.empty()) continue;
        answer += pq.top();
        pq.pop();
    }

    return answer;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        arr.push_back({a,b});
    }
    cout<<solve();
    return 0;
}