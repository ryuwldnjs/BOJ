#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<int> a,prefix,suffix;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    a.resize(n);
    prefix.resize(n);
    suffix.resize(n);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    prefix[0] = a[0];
    suffix[n-1] = a[n-1];
    for(int i=1;i<n;i++) prefix[i] = gcd(prefix[i-1], a[i]);
    for(int i=n-2;i>=0;i--) suffix[i] = gcd(suffix[i+1], a[i]);
    
    int answer=-1;
    int K=-1;

    //k = a[i]일때
    for(int i=0;i<n;i++){
        int GCD;
        if(i==0) GCD = suffix[i+1];
        else if(i == n-1) GCD = prefix[i-1];
        else GCD = gcd(prefix[i-1], suffix[i+1]);

        if(a[i] % GCD == 0) continue;
        if(answer < GCD){
            answer = GCD;
            K = a[i];
        }
    }
    
    if(answer == -1) cout<<-1;
    else cout<<answer<<' '<<K;
    return 0;
}