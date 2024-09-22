#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;
using ll=long long;

struct Relic{
    ll x1=INF,y1=INF;
    ll x2=-INF,y2=-INF;

    void udpate(ll h, ll v){
        x1 = min(x1, v);
        y1 = min(y1, h);
        x2 = max(x2, v);
        y2 = max(y2, h);
    }

    ll getSize(){
        if(x1 == INF) return 0;
        return (x2-x1+1) * (y2-y1+1);
    }
};
vector<Relic> relic;
int r,c,n;
int MAX;
int main(){
    cin>>r>>c>>n;
    relic.resize(n+1);
    for(int i=0;i<n;i++){
        ll a,h,v; cin>>a>>h>>v;
        relic[a].udpate(h,v);
    }

    for(int i=1;i<relic.size(); i++){
        if(relic[MAX].getSize() < relic[i].getSize()) MAX = i;
    }

    cout<<MAX<<' '<<relic[MAX].getSize();
    return 0;
}