#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
#define INF (ll)1e15

struct Info{
    ll weight, price;

    bool operator<(const Info& other)const{
        if(price == other.price) return weight > other.weight;

        return price < other.price; 
    }
};

vector<Info> arr;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n,m;cin>>n>>m;

    for(ll i=0;i<n;i++){
        ll weight,price;cin>>weight>>price;
        arr.push_back({weight,price});
    }
    arr.push_back({0, INF});

    sort(arr.begin(), arr.end());


    // ll last_w=-1, last_p=-1;
    ll p_weight=0;
    ll p_price=0;
    ll answer = INF;

    for(ll i=0;i<n;i++){
        p_weight += arr[i].weight;
        
        if(i && arr[i-1].price == arr[i].price){
            p_price += arr[i].price;
        }
        else{
            p_price = arr[i].price;
        }

        //어? 충분한데?
        if(p_weight >= m){
            answer = min(answer, p_price);
        }

    }

    if(answer == INF) cout<<-1;
    else cout<<answer;
    return 0;
}