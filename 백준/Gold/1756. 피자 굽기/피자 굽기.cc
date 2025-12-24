#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define INF 1e9

vector<int> oven;

int d,n;
int idx;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>d>>n;
    oven.resize(d+2);

    oven[0] = INF;
    oven[d+1] = 0;
    for(int i=1;i<=d;i++) {
        cin>>oven[i];
        oven[i] = min(oven[i-1], oven[i]);
    }


    idx = d+1;

    for(int i=0;i<n;i++){
        int x;cin>>x;
        
        idx--;
        while(idx>0 && oven[idx] < x) idx--;
    }
    if(idx < 0) idx = 0;
    cout<<idx;
    return 0;
}