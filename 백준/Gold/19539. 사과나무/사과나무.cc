#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    
    int total = 0;
    int two = 0;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        total += x;
        two += x / 2;
    }
    

    if(total%3 == 0 && two >= total/3) cout<<"YES";
    else cout<<"NO";
    return 0;
}