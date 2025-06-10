#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<set<int>> sets;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,q;cin>>n>>q;
    sets.resize(n+1);

    for(int i=1;i<=n;i++){
        int x;cin>>x;
        while(x--){
            int s;cin>>s;
            sets[i].insert(s);
        }
    }

    while(q--){
        int com;cin>>com;
        if(com == 1){
            int a,b;cin>>a>>b;
            if(sets[a].size() < sets[b].size()) swap(sets[a], sets[b]);
            sets[a].insert(sets[b].begin(), sets[b].end());
            sets[b].clear();
        }
        else{
            int a;cin>>a;
            cout<<sets[a].size()<<'\n';
        }
    }
    return 0;
}