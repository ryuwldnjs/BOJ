#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
using ll=long long;
ll n,ans;
vector<int> arr;
int main(){
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    for(ll i=0;i<n;i++){
        ans += abs(arr[i] - i-1LL);
    }
    cout<<ans;
    return 0;
}