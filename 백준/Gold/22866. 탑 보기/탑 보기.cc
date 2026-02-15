#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define INF (ll)1e9

int n;
int building[100000+5];

void play(vector<pii> &seen){//[cnt, 빌딩idx]
    stack<pii> s; // [idx, height]
    s.push({0, INF});

    vector<int> next(n+2,-1);
    for(int i=1;i<=n;i++){
        while(s.top().second < building[i]){
            next[s.top().first] = i;
            s.pop();
        }
        s.push({i, building[i]});
    }

    for(int i=n;i>=1;i--){
        int nn = next[i]; // i빌딩보다 크고 가장 가까운 우측 빌딩
        // printf("%d: %d\n", i, nn);
        if(nn == -1) continue;

        seen[i].first += seen[nn].first + 1;
        seen[i].second = nn;
        // if(seen[i].second == -1) seen[i].second = nn;
        // else{
        //     if(abs(nn - i) <= abs(seen[i].second - i)) seen[i].second = nn;
        // }
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>building[i];
    }
    building[0] = building[n+1] = INF;

    vector<pii> seenL(n+2, {0, -1}), seenR(n+2, {0, -1});
    play(seenR);
    reverse(building, building + n+2);
    play(seenL);
    reverse(seenL.begin(), seenL.end());

    for(int i=1;i<=n;i++){
        int cnt = seenR[i].first + seenL[i].first;
        cout<<cnt;
        if(cnt == 0){
            cout<<'\n';
            continue;
        }

        cout<<' ';
        if(abs(n-seenL[i].second+1 - i) <= abs(seenR[i].second - i)) cout<<n-seenL[i].second+1;
        else cout<<seenR[i].second;
        cout<<'\n';
    }
    return 0;
}