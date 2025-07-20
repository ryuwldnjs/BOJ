#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    vector<int> h(n);
    stack<int> s;
    for(int i=0;i<n;i++) cin>>h[i];
    
    
    ll answer = 0;
    for(int i=0;i<n;i++){
        while(!s.empty() && s.top() <= h[i]) s.pop();
        answer += (ll) s.size();
        s.push(h[i]);
    }

    cout<<answer;
    return 0;
}