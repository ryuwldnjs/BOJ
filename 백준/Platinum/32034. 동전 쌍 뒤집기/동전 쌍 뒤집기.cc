#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

void solve(){
    int n;cin>>n;
    string s; cin>>s;
    int cnt_T = count(s.begin(), s.end(), 'T');
    if(cnt_T % 2 != 0){
        cout<<"-1\n";
        return;
    }


    stack<ll> idx;
    ll answer = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'H') continue;
        //T일때만 생각
        if(idx.empty()){
            idx.push(i);
            continue;
        }

        ll cnt = (ll) i - idx.top() - 1;
        //T사이에 H 짝수개 존재가능성이 있을때
        if(cnt % 2 == 0){
            answer += cnt + 1;
            idx.pop();
        }
        //괄호매칭처럼, 나중에 나오는 T가 앞선 T들을 해소할수도 있음
        else idx.push(i);
    }

    //끝까지 해소되지 않은 T가 존재한다면
    if(!idx.empty()) cout<<"-1\n";
    else cout<<answer<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}