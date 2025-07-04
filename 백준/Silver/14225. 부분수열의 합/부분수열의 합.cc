#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
unordered_map<int, bool> exist;
int n;
vector<int> a;
void make(int idx, int sum){
    if(idx == n) {
        exist[sum] = true;
        return;
    }

    make(idx+1, sum);
    make(idx+1, sum + a[idx]);
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    make(0, 0);

    for(int i=1;i<=2000000;i++){
        if(!exist.count(i)){
            cout<<i;
            return 0;
        }
    }
    return 0;
}