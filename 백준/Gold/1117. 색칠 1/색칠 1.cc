#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

void solve(){
    ll answer = 0;
    ll W,H,f,c,x1,y1,x2,y2;
    cin>>W>>H>>f>>c>>x1>>y1>>x2>>y2;

    ll threshold = min(f, W-f);


    //기본
    answer += (x2 - x1) * (y2 - y1);
    //두배 이벤트
    if(x1 < threshold){
        answer += (min(threshold, x2) - x1) * (y2 - y1);
    }
    //c+1배 이벤트
    answer *= (c+1);
    answer = W*H - answer;
    cout<<answer;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();
    return 0;
}