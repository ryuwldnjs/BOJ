#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<int> s[1000000+5], e[1000000+5];

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        s[a].push_back(b);
        e[b].push_back(a);
    }
    for(int i=0;i<=1000000;i++){
        sort(s[i].begin(), s[i].end());
        sort(e[i].begin(), e[i].end());
    }

    int q;cin>>q;
    while(q--){
        int a,b;cin>>a>>b;
        auto it1 = lower_bound(s[a].begin(), s[a].end(), b);
        
        if(it1 == s[a].end() || e[b].empty() || a < e[b].front()){
            cout<<"-1\n";
        }
        else if(*it1 == b) cout<<"1\n";
        else cout<<"2\n";
    }
    return 0;
}