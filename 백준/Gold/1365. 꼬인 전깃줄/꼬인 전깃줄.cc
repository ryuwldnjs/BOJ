#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<int> LIS;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        int idx = lower_bound(LIS.begin(), LIS.end(), x) - LIS.begin();
        if(idx == LIS.size()) LIS.push_back(x);
        else LIS[idx] = x;
    }

    cout<<n - LIS.size();
    return 0;
}