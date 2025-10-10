#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n,m;
int a[1005][1005];
int cache[1005]; //j열에 대해 최댓값
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;cin>>x;
            a[i][j] = abs(a[i][j] - x);
        }
    }

    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            cache[j] = max(cache[j], a[i][j]);
        }
    }

    int answer = 0;
    for(int i=0;i<m;i++){
        int x;cin>>x;
        x--;
        answer += cache[x];
    }

    cout<<answer;
    return 0;
}