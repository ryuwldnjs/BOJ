#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii=pair<int,int>;

int n;
vector<pii> x;
int main(){
    cin>>n;
    x.resize(n);
    for(int i=0;i<n;i++){
        cin>>x[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>x[i].second;
    }
    x.push_back({0, 0});

    sort(x.begin(), x.end(), greater<pii>());
    int time = max(x[0].first, x[0].second);

    for(int i=1;i<x.size();i++){
        int distance = abs(x[i].first - x[i-1].first);
        int cost = max(x[i].second - time, 0);
        time += max(distance, cost);
    }
    cout<<time;
    return 0;
}