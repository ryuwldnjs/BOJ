#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
ll n,me;
vector<ll> arr;
int main(){
    cin>>n;
    cin>>me;
    arr.resize(n-1);
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    for(int i=0;i<arr.size();i++){
        if(me > arr[i]){
            me += arr[i];
        }
        else{
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}