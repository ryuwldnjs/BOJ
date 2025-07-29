#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<int> a,b;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;


    for(int i=n;i>=3;i-=3){
        a.push_back(i);
        b.push_back(i-1);
        b.push_back(i-2);
    }
    if(b.empty() || b.back() > 2){
        a.push_back(2);
        b.push_back(1);
    }

    cout<<a.size()<<'\n';
    for(int i:a) cout<<i<<' ';
    cout<<'\n';
    cout<<b.size()<<'\n';
    for(int i:b) cout<<i<<' ';
    
    return 0;
}