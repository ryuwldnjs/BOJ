#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
vector<ll> a,b;
ll n,c;
ll answer;
int main(){
    cin>>n>>c;
    a.push_back(0);
    b.push_back(0);
    for(int i=0;i<n/2;i++){
        ll x; cin>>x;
        int sz = a.size();
        for(int j=0;j<sz;j++){
            a.push_back(a[j] + x);
        }

    }

    for(int i=n/2;i<n;i++){
        ll x; cin>>x;
        int sz = b.size();
        for(int j=0;j<sz;j++){
            b.push_back(b[j] + x);
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());


    int target = b.size()-1;
    for(int i=0;i<a.size();i++){
        ll limit = c - a[i];
        while(target >= 0 && b[target] > limit) target--;
        answer += target + 1;
    }
    cout<<answer;
    return 0;
}