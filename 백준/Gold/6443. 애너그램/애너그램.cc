#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int alpha[26];
int n;
string now;
void find(int idx){
    if(idx == n){
        cout<<now<<'\n';
        return;
    }

    for(int i=0;i<26;i++){
        if(alpha[i]){
            alpha[i]--;
            now.push_back('a' + i);
            find(idx + 1);
            alpha[i]++;
            now.pop_back();
        }
    }
}

void solve(){
    string s;cin>>s;
    fill(alpha, alpha + 26, 0);
    n = s.size();
    for(char c: s){
        alpha[c - 'a']++;
    }

    find(0);
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}