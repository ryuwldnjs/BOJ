#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;

ll n, command;
ll fact[21] = {1,1};
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    for(ll i=2;i<=20;i++) fact[i] = fact[i-1] * i;
    vector<ll> nums;
    
    cin>>n>>command;
    for(ll i=1;i<=n;i++) nums.push_back(i);

    if(command == 1){
        ll k;cin>>k;
        k--;
        vector<ll> answer;

        for(ll i=n-1;i>=0;i--){
            ll idx = k / fact[i];
            k %= fact[i];

            answer.push_back(nums[idx]);
            nums.erase(nums.begin() + idx);
        }

        for(ll i: answer) cout<<i<<' ';
    }
    else{


        ll answer = 0;
        for(ll i=n-1;i>=0;i--){
            ll a; cin>>a;
            ll idx = find(nums.begin(), nums.end(), a) - nums.begin();
            answer += fact[i] * idx;
            nums.erase(nums.begin() + idx);
        }
        
        answer++;
        cout<<answer;
    }
    return 0;
}