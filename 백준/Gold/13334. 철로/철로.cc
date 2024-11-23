#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using pii=pair<int,int>;
int n, d, MAX;
vector<pii> arr;
priority_queue<int,vector<int>, greater<int>> pq;
bool cmp(pii a, pii b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second; 
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        if(a > b) swap(a,b);
        arr.push_back({a,b});
    }
    cin>>d;
    sort(arr.begin(), arr.end(), cmp);
    
    for(int i=0;i<n;i++){
        pq.push(arr[i].first);
        while(!pq.empty() && pq.top() < arr[i].second - d) pq.pop();
        MAX = max(MAX, (int) pq.size());
    }
    cout<<MAX;
    return 0;
}  