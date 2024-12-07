#include<iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int n, MAX;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        pq.push(x);
        MAX = max(MAX, x - pq.top());
    }
    cout<<MAX;
    return 0;
}