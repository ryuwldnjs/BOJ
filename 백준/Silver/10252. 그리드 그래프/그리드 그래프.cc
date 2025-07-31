#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int n,m;

void solve(){
    cin>>n>>m;
    printf("1\n");
    for(int i=0;i<n;i++){
        printf("(%d,%d)\n", i, 0);
    }

    for(int i=n-1;i>=0;i--){
        if(i%2 == (n-1)%2)
            for(int j=1;j<m;j++){
                printf("(%d,%d)\n", i, j);
            }
        else
            for(int j=m-1;j>0;j--){
                printf("(%d,%d)\n", i, j);
            }
        
    }

}

int main(){
    // cin.tie(0) -> sync_with_stdio(0);
    int t; scanf("%d", &t); while(t--) solve();
    return 0;
}