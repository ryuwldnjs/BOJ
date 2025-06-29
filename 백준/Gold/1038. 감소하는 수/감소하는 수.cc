#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<ll> nums;
void makeNum(ll num){
    nums.push_back(num);
    
    ll last = num%10;
    for(int i=0;i<last;i++){
        makeNum(num*10 + i);
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    
    for(int i=0;i<10;i++) makeNum(i);
    sort(nums.begin(), nums.end());

    if(n >= nums.size()) cout<<-1;
    else cout<<nums[n];
    
    return 0;
}