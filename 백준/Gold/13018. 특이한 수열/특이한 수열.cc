#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,k;cin>>n>>k;
    if(n == k){
        cout<<"Impossible";
        return 0;
    }

    vector<int> answer;
    for(int i=1;i<=n;i++) answer.push_back(i);
    // 1 2 3 4
    for(int i=0;i<n-k-1;i++) answer[i] = answer[i+1];
    answer[n-k-1] = 1;

    for(int i:answer) cout<<i<<' ';
    return 0;
}