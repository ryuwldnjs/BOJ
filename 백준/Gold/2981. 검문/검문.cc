#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin>>n;
    vector<int> arr(n);
    for(int &i: arr) cin>>i;
    sort(arr.begin(), arr.end());

    ll GCD = arr[1] - arr[0];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int gap = arr[j] - arr[i];
            GCD = gcd(GCD, gap);
        }
    }
    set<int> s;
    for(int i=2; i*i<=GCD; i++){
        if(GCD % i == 0){
            s.insert(i);
            s.insert(GCD/i);
        }
    }
    s.insert(GCD);
    vector<int> answer(s.begin(), s.end());
    for(int i: answer){
        cout<<i<<' ';
    }
    return 0;
}   