#include <iostream>
#include <algorithm>
using namespace std;
int n, cost[10], m;
string MAX;

string dp[55];
// dp[i] : i원일때의 최대 방번호

bool cmp(string a, string b){
    if(a.size()==b.size()){
        for(int i=0;i<a.size();i++){
            if(a[i] != b[i]) return a[i] < b[i];
        }
    }
    return a.size() < b.size();
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            string tmp;
            if(i - cost[j] >= 0) tmp = dp[i - cost[j]] + to_string(j);
            sort(tmp.begin(), tmp.end(), greater<char>());
            if(tmp.front()=='0') continue;
            dp[i] = max(dp[i], tmp, cmp);

        }
        sort(dp[i].begin(), dp[i].end(), greater<char>());
    }
    for(int i=1;i<=m;i++){
        if(dp[i].empty()) continue;
        MAX = max(MAX, dp[i], cmp);
    }
    if(MAX == "") MAX = "0";
    cout<<MAX;
    return 0;
}