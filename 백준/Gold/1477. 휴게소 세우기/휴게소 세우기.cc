#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n,m,l;
vector<int> station;

//최대간격이x일때 m개 휴게소 설치가 가능한가
bool able(int x){
    int cnt = 0;

    for(int i=1;i<n+2;i++){
        int gap = max(0,station[i] - station[i-1] - 1);
        cnt += gap / x;
    }

    // printf("%d: %d\n", x,cnt);

    return cnt <= m;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m>>l;
    station.resize(n+2);
    for(int i=1;i<=n;i++){
        cin>>station[i];
    }
    station[0] = 0;
    station[n+1] = l;
    sort(station.begin(), station.end());

    for(int i=1;i<=l;i++){
        if(able(i)){
            cout<<i;
            return 0;
        }
    }
    return 0;
}