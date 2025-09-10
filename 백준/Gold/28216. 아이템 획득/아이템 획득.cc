#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
struct Info{
    ll pos;
    ll w;

    bool operator<(const Info &other)const{
        return pos < other.pos;
    }
    bool operator<(const ll other)const{
        return pos < other;
    }
};
ll dx[4] = {1,0,-1,0};
ll dy[4] = {0,1,0,-1};

vector<Info> x[200000+5], y[200000+5];
vector<ll> psum_x[200000+5], psum_y[200000+5];


//[lo, hi]구간 아이템 가중치 합
ll getItem(vector<Info> &arr, vector<ll> &psum, ll lo, ll hi){
    
    ll idx1 = lower_bound(arr.begin(), arr.end(), lo) - arr.begin();
    ll idx2 = lower_bound(arr.begin(), arr.end(), hi+1) - arr.begin() - 1;
    // printf("%d %d\n", idx1, idx2);
    if(idx1 > idx2) return 0;

    ll ret = psum[idx2] - (idx1>0 ? psum[idx1-1] : 0);
    // printf(":%d\n", ret);
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n,q;cin>>n>>q;
    for(ll i=0;i<n;i++){
        ll a,b,w;cin>>a>>b>>w;
        x[a].push_back({b,w});
        y[b].push_back({a,w});
    }

    for(ll i=1;i<=200000;i++){
        sort(x[i].begin(), x[i].end());
        sort(y[i].begin(), y[i].end());
        
        psum_x[i].resize(x[i].size());
        if(x[i].size()) psum_x[i][0] = x[i][0].w;
        for(ll j=1;j<x[i].size();j++){
            psum_x[i][j] = psum_x[i][j-1] + x[i][j].w;
        }


        psum_y[i].resize(y[i].size());
        if(y[i].size()) psum_y[i][0] = y[i][0].w;
        for(ll j=1;j<y[i].size();j++){
            psum_y[i][j] = psum_y[i][j-1] + y[i][j].w;
        }
    }


    ll answer = 0;

    ll nowx=1, nowy=1;
    while(q--){
        ll d,v;cin>>d>>v;

        ll nextx = nowx + dx[d]*v;
        ll nexty = nowy + dy[d]*v;

        if(d==0){ //y고정, x증가
            answer += getItem(y[nowy], psum_y[nowy], nowx+1, nextx);
        }
        else if(d==1){ //x고정, y증가
            answer += getItem(x[nowx], psum_x[nowx], nowy+1, nexty);
        }
        else if(d==2){ //y고정, x감소
            answer += getItem(y[nowy], psum_y[nowy], nextx, nowx-1);
        }
        else if(d==3){ //x고정, y감소
            answer += getItem(x[nowx], psum_x[nowx], nexty, nowy-1);
        }

        nowx = nextx;
        nowy = nexty;

    }


    cout<<answer;
    return 0;
}