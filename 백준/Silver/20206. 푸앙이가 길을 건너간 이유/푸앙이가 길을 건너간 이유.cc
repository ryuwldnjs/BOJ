#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

//ax + by + c = 0;
ll a,b,c;
ll f(ll x, ll y){
    return a*x + b*y + c;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>a>>b>>c;
    ll x1,x2,y1,y2;
    cin>>x1>>x2>>y1>>y2;

    bool isLucky = false;
    
    if(f(x1,y1)>=0 && f(x1,y2)>=0 && f(x2,y1)>=0 && f(x2,y2)>=0 
        || f(x1,y1)<=0 && f(x1,y2)<=0 && f(x2,y1)<=0 && f(x2,y2)<=0) isLucky = true;

    if(isLucky) cout<<"Lucky";
    else cout<<"Poor";
    return 0;
}