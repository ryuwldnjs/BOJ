#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
vector<int> a;

int getIdx(int val){
    for(int i=0;i<a.size();i++){
        if(a[i] == val) return i;
    }
    return -1;
}

void solve(){
    int n;cin>>n;
    a = vector<int>(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    if(n == 1){
        cout<<"0\n";
        return;
    }

    vector<int> answer;
    //크기가 i인 팬케이크를 찾아 두번 뒤집기
    for(int i=n;i>=3;i--){
        int idx = getIdx(i);
        reverse(a.begin(), a.begin() + idx+1);
        reverse(a.begin(), a.begin() + i); 
        answer.push_back(idx+1);
        answer.push_back(i);
    }


    if(a[0] > a[1]) answer.push_back(2);

    cout<<answer.size()<<' ';
    for(int i:answer) cout<<i<<' ';
    cout<<'\n';

}



int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}