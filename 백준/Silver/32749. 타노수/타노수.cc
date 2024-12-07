#include <iostream>
#include <string>
using namespace std;
using ll=long long;
ll n,t;
string num, MAX;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>t;
    cin>>num;
    ll gap = 1LL<<(n - t);
    for(ll i=0;i<num.size(); i+= gap){
        string target = num.substr(i, gap);
        // printf(":%lld ", target);
        // cout<<target<< ' ';
        MAX = max(MAX, target);
    }
    cout<<MAX;
    return 0;
}