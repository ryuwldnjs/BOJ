#include <iostream>
using namespace std;
using ll=long long;
ll n, arr[1000000];
ll total, answer;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        total += arr[i];
    }
    ll NEEDED = total / n;

    for(ll i=0;i<n-1;i++){
        ll diff = arr[i] - NEEDED;
        arr[i+1] += diff;
        answer += abs(diff); // 건네줬거나, 받았거나 둘다 카운팅
    }
    cout<<answer;
    return 0;
}