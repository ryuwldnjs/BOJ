#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
#define SIZE 32LL

ll arr[1005];

string getIP(ll num){
    string ret="";
    for(ll i=0;i<4;i++){
        ret = to_string(num % 256LL) + "." + ret;
        num /= 256LL;
    }
    ret.pop_back();
    return ret;
}
int main(){
    ll n;
    scanf("%lld", &n);    

    for(ll i=0;i<n;i++){
        ll a,b,c,d;
        scanf("%lld.%lld.%lld.%lld", &a,&b,&c,&d);
        arr[i] = arr[i]*(1LL<<8) + a;
        arr[i] = arr[i]*(1LL<<8) + b;
        arr[i] = arr[i]*(1LL<<8) + c;
        arr[i] = arr[i]*(1LL<<8) + d;

    }

    ll network = 0;
    ll mask = 0;
    ll m = SIZE;

    for(ll bit=SIZE-1;bit>=0;bit--){
        ll target = (arr[0] & (1LL<<bit));
        for(ll i=0;i<n;i++){
            if((arr[i]&(1LL<<bit)) != target){
                m = bit;
                break;
            }
        }

        if(m != SIZE) break;
        network |= target;
        if(bit == 0) m = -1;
    }


    for(ll bit=SIZE-1;bit>m;bit--){
        mask |= 1LL<<bit;
    }

    cout<<getIP(network)<<'\n';
    cout<<getIP(mask);
    return 0;
}