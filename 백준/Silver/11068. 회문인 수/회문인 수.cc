#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

void solve(){
    int x;cin>>x;
    
    for(int i=2;i<=64;i++){
        int num = x;
        vector<int> nums;
        while(num){
            nums.push_back(num % i);
            num /= i;
        }

        bool isAnswer = true;
        for(int i=0;i<nums.size()/2; i++){
            if(nums[i] != nums[nums.size() - i - 1]) isAnswer = false;
        }

        if(isAnswer){
            cout<<1<<'\n';
            return;
        }
    }
    cout<<0<<'\n';
    return;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}