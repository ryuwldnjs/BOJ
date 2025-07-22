#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
// f : ax + b
struct Line{
    ll a,b;
    double start;

    bool operator<(const double x)const{
        return start <= x;
    }
};

//두 직선의 교점 x
double cross(Line &f, Line &g){
    return (g.b - f.b) / (f.a - g.a);
}

vector<Line> f;
vector<ll> dp;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    dp.resize(n);
    vector<ll> a(n), b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    for(int i=1;i<n;i++){
        Line g = {b[i-1], dp[i-1], 0};
        while(!f.empty()){
            g.start = cross(f.back(), g);
            if(f.back().start < g.start) break;
            f.pop_back();
        }
        f.emplace_back(g);

        ll x = a[i];
        int idx = lower_bound(f.begin(), f.end(), x) - f.begin();
        if(idx>0) idx--;
        // if(idx < f.size()) x = f[idx].start;

        dp[i] = f[idx].a * x + f[idx].b;
        // printf("%d:%lld\n",i,idx);
    }
    cout<<dp[n-1];
    return 0;
}