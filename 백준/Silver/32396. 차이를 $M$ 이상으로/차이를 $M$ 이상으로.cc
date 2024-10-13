#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
ll n,m, ans;
vector<ll> arr;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        ll x; cin>>x;
        arr.push_back(x);
    }
    for(int i=1;i<n;i++){
        if(m > abs(arr[i] - arr[i-1])){
            ans++;
            i++;
        }
    }
    cout<<ans;
    return 0;
}