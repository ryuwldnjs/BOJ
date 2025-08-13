#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<int> lis;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        int idx = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
        if(idx == lis.size()) lis.push_back(x);
        else lis[idx] = x;
    }

    cout<< n - lis.size();
    return 0;
}