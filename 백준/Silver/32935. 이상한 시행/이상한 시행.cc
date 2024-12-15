#include <iostream>
using namespace std;
using ll=long long;
ll n,MAX = 0, sum;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        ll x; cin>>x;
        sum += x;
        MAX = max(MAX, -x);
    }
    cout<<max(MAX, sum);
    return 0;
}