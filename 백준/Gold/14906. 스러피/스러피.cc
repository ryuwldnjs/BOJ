#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

bool isSlump(string s){
    int len = s.size();
    if(len <= 1) return false;

    if(s[0]!='D' && s[0]!='E') return false;
    if(s[1] != 'F') return false;
    
    int idx = 1;
    while(idx+1<len && s[idx] == 'F') idx++;
    
    if(idx==len-1){
        if(s[idx] == 'G') return true;
        else return false;
    }

    return isSlump(s.substr(idx));
}

bool isSlimp(string s){
    int len = s.size();
    if(len <= 1) return false;
    if(s[0] != 'A') return false;

    if(len == 2){
        if(s[1] == 'H') return true;
        else return false;
    }

    if(s.back() != 'C') return false;
    
    if(s[1] == 'B') return isSlimp(s.substr(2, len-3));
    else return isSlump(s.substr(1, len-2));
}

void solve(){
    string str;cin>>str;
    int n = str.size();

    
    for(int i=1;i<n-1;i++){
        // printf("%d %d\n", isSlimp(str.substr(0,i)),isSlump(str.substr(i)));
        if(isSlimp(str.substr(0,i)) && isSlump(str.substr(i))){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
    return;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cout<<"SLURPYS OUTPUT\n";
    int t; cin>>t; while(t--) solve();
    cout<<"END OF OUTPUT";

    // cout<<isSlimp("ADFGC");
    return 0;
}