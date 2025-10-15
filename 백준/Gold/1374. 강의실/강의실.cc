#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int a,b,c;
    bool operator<(const Info &other)const{
        return b < other.b;
        
    }
};
vector<Info> arr;
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        arr.push_back({a,b,c});
    }
    sort(arr.begin(), arr.end());

    pq.push(arr[0].c);
    for(int i=1;i<n;i++){
        int endtime = pq.top();
        if(endtime <= arr[i].b) pq.pop();
        pq.push(arr[i].c);
    }

    cout<<pq.size();
    return 0;
}