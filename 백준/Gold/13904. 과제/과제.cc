#include <iostream>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int> pq;
vector<vector<int>> days;
int n, ans;
int main(){
    cin>>n;
    days.resize(1000+1);
    for(int i=0;i<n;i++){
        int d,w; cin>>d>>w;
        days[d].push_back(w);
    }
    for(int i=1000;i>=1;i--){
        for(int j=0;j<days[i].size();j++){
            pq.push(days[i][j]);
        }
        if(pq.empty()) continue;

        ans += pq.top();
        pq.pop();
    }
    cout<<ans;
    return 0;
}