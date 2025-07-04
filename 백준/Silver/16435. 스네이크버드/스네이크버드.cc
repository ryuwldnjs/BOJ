#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int n,l;
vector<int> h;
vector<bool> visited;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>l;
    h.resize(n);
    visited.resize(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    int it=1000;
    while(it--){
        for(int i=0;i<n;i++){
            if(!visited[i] && h[i] <= l){
                visited[i] = true;
                l++;
            }
        }
    }
    cout<<l;
    return 0;
}