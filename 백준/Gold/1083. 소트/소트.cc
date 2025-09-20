#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n, s;
int a[55];

int findTarget(int idx){
    int target = idx;
    for(int i=idx; i<n&&i<=idx+s; i++){
        if(a[target] < a[i]) target = i;
    }
    return target;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>s;

    for(int i=0;i<n;i++){
        int target = findTarget(i);
        if(i == target) continue;

        int tmp = a[target];
        for(int j=target; j>i; j--){
            a[j] = a[j-1];
        }
        a[i] = tmp;

        s -= target - i;
    }


    for(int i=0;i<n;i++) cout<<a[i]<<' ';
    return 0;
}