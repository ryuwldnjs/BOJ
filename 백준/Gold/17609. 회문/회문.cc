#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

bool isPalindrome(string &s, int l, int r){
    string a = s.substr(l, r-l+1);
    string b = a;
    reverse(b.begin(), b.end());
    return a == b;
}
void solve(){
    string s; cin>>s;
    int l=0, r = s.size()-1;
    while(l < r){
        // printf("%d %d:%d\n",l,r,chance);
        if(s[l] == s[r]){
            l++;
            r--;
        }
        else{
            if(isPalindrome(s, l+1,r) || isPalindrome(s, l, r-1)){
                cout<<"1\n";
            }
            else{
                cout<<"2\n";
            }
            return;
        }
    }
    cout<<"0\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}