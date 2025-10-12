#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int d,t;

    bool operator<(const Info& other)const{
        return t > other.t;
    }
};
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    vector<Info> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i].d>>a[i].t;
    }


    sort(a.begin(), a.end());

    int last = 2e9;
    for(int i=0;i<n;i++){
        last = min(last - a[i].d, a[i].t - a[i].d);
    }

    cout<<last;
    return 0;
}