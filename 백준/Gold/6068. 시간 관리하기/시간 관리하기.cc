#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int s,t;

    bool operator<(const Info &other)const{
        return t > other.t;
    }
};

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    vector<Info> a(n);
    for(int i=0;i<n;i++){
        int s,t;cin>>s>>t;
        a[i] = {s,t};
    }

    sort(a.begin(), a.end());
    int time = 1e9;
    for(int i=0;i<n;i++){
        time = min(time - a[i].s, a[i].t - a[i].s);
    }

    if(time < 0) cout<<-1;
    else cout<<time;
    return 0;
}