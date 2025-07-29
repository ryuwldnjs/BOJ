#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    
    for(int i=(n+1)/2;i>=1;i--){
        cout<< i << ' ';
        
        if(i + n/2 > (n+1)/2) cout<< i + n/2 <<' ';
    }
    
    
    return 0;
}