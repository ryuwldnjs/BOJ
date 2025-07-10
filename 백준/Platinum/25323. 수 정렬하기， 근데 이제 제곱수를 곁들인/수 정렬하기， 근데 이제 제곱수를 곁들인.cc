#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    ll idx;
    ll val;
    bool operator<(const Info &other)const{
        if(val == other.val) return idx < other.idx;
        return val < other.val;
    }
};

vector<ll> arr;
vector<Info> sorted_arr;

bool isSquare(ll a, ll b){
    ll GCD = gcd(a, b);
    a /= GCD;
    b /= GCD;
    ll sqrt_a = sqrt(a);
    ll sqrt_b = sqrt(b);
    
    //교환 가능
    return sqrt_a*sqrt_a == a && sqrt_b*sqrt_b == b;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    arr.resize(n);
    sorted_arr.resize(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
        sorted_arr[i] = {i, arr[i]};
    }

    sort(sorted_arr.begin(), sorted_arr.end());

    for(int i=0;i<n;i++){
        if(i == sorted_arr[i].idx) continue;
        ll before = sorted_arr[i].idx;
        ll after = i;

        if(!isSquare(arr[before], arr[after])){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";

    return 0;
}