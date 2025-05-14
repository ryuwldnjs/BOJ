#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n,h;
vector<int> bot,top;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>h;
    bot.resize(n/2);
    top.resize(n/2);
    for(int i=0;i<n/2;i++){
        cin>>bot[i]>>top[i];
    }

    sort(bot.begin(), bot.end());
    sort(top.begin(), top.end());
    
    int MIN=1e9, cnt=1;
    for(int i=1;i<=h;i++){
        int b = bot.end() - lower_bound(bot.begin(), bot.end(), i);
        int t = top.end() - lower_bound(top.begin(), top.end(), h-i+1);
        if(MIN > b + t){
            MIN = b + t;
            cnt = 1;
        }
        else if(MIN == b + t) cnt++;
    }
    cout<<MIN<<' '<<cnt;
    return 0;
}