#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n;
vector<int> a;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    a.resize(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());


    int last = 0;
    for(int i=0;i<n;i++){
        if(last + 1 >= a[i]) last += a[i];
    }

    cout<<last+1;
    return 0;
}