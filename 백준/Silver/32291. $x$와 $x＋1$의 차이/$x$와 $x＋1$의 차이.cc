#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
ll x;
vector<ll> ans;
int main(){
    cin>>x;
    x++;    
    for(ll i=1;i*i<=x;i++){
        if(x%i == 0){
            ans.push_back(i);
            if(i*i != x && x/i < x) ans.push_back(x/i);
        } 
        
    }
    sort(ans.begin(), ans.end());
    for(auto x: ans){
        cout<<x<<' '; 
    }
    return 0;
}