#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    ll val;
    ll l, r;

    bool operator<(const Info& other)const{
        return val < other.val;
    }
};

const ll INF = 1e17;

void solve(){
    ll n;cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<Info> arr;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            arr.push_back({a[i] + a[j], i, j});
            
        }
    }

    sort(arr.begin(), arr.end());


    ll answer = INF;
    for(int i=1;i<arr.size();i++){

        for(int j=i-1;j>=0 && j>= i-10 ;j--){
            ll gap = abs(arr[j].val - arr[i].val);
            set<ll> s = {arr[j].l, arr[j].r, arr[i].l, arr[i].r};

            if(s.size() < 4) continue;
            answer = min(answer, gap);

        }

    }

    cout<<answer;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();
    return 0;
}