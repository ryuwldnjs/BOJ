#include<bits/stdc++.h>
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
using namespace std;
using ll = long long;

ll ccw(pair<ll, ll>p1, pair<ll, ll>p2, pair<ll, ll>p3) {
    ll s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

    if (s > 0) return 1;
    else if (s == 0) return 0;
    else return -1; 
}

struct line{
    ll sx;
    ll sy;
    ll ex;
    ll ey;
    ll w;
    bool operator<(const line&other)const{
        return w < other.w;
    }
};

// set<ll> us[2501];
vector<ll> us[2501];
vector<line> v;
struct cmp
{
    bool operator()(pair<ll,ll> a,pair<ll,ll> b) const {
        if(a.second == b.second) return v[a.first].w<v[b.first].w;
        return a.second<b.second;
    }
};


int main(void) {
    fastio

    ll n; cin>>n;
    v.resize(n+1);

    for(ll i=1;i<=n;i++) {
        cin>>v[i].sx>>v[i].sy>>v[i].ex>>v[i].ey>>v[i].w;
    }

    sort(v.begin()+1, v.end());

    for(ll i=1;i<n;i++) {
        for(ll j=i+1;j<=n;j++) {
            pair<ll,ll> p1 = {v[i].sx,v[i].sy};
            pair<ll,ll> p2 = {v[i].ex,v[i].ey};

            pair<ll,ll> p3 = {v[j].sx,v[j].sy};
            pair<ll,ll> p4 = {v[j].ex,v[j].ey};

            if(ccw(p1,p2,p3) * ccw(p1,p2,p4)<=0 && ccw(p3,p4,p1) * ccw(p3,p4,p2)<=0) {

                us[i].push_back(j);
                us[j].push_back(i);
        //      us[i].insert(j);
                // us[j].insert(i);
            }

        }
    }
    
    ll answer = 0;
    for(int i=n;i>=1;i--){
        sort(us[i].begin(), us[i].end());
        ll cnt = us[i].end() - lower_bound(us[i].begin(), us[i].end(), i);
        answer += v[i].w * (cnt+1);
    }
    cout<<answer;


    // vector<ll> weight(n+1);
    // set<pair<ll,ll>,cmp> fuck;

    // for(ll i=1;i<=n;i++) {
    //     ll tmp = v[i].w * (us[i].size()+1LL);
    //     fuck.insert({i,tmp});
    //     weight[i] = tmp;
    // }

    // ll ans = 0;
    // ll cnt = 0;

    // while(cnt<n) {
    //     auto it = fuck.begin();
    //     // printf("%d ", it->first);
    //     // fuck.erase(it);
    //     ll num = it->first;
    //     // printf("%d", it->first);

    //     ll energy = it->second;
    //     fuck.erase(it);
    //     ans += energy;
    //     cnt++;
    //     for(auto k=us[num].begin();k!=us[num].end();k++) {
    //         ll a = *k;
    //         us[a].erase(num);
    //         fuck.erase({a,weight[a]});
    //         weight[a] -= v[a].w;
    //         fuck.insert({a,weight[a]});
    //     }
    // }
    // cout<<ans;
}