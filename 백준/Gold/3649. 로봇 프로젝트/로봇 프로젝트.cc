#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int x;
void solve(){
    x *= 10000000;
    int n;cin>>n;
    vector<int> a(n);
    unordered_map<int, int> cache;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cache[a[i]]++;
    }
    sort(a.begin(), a.end());

    for(int i=0;i<n;i++){
        int target = x - a[i];
        if(cache.count(target) == 0) continue;
        if(a[i] != target || cache[target] >= 2){
            cout<<"yes "<<a[i]<<' '<<target<<'\n';
            return;
        }
    }

    cout<<"danger\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    while(cin>>x) solve();
    return 0;
}