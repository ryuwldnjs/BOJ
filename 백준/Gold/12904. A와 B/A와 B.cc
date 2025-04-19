#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    string s,t;
    cin>>s>>t;
    int iter = t.size() - s.size();
    while(iter--){
        if(t.back() == 'A') t.pop_back();
        else{
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    if(s == t) cout<<1;
    else cout<<0;
    return 0;
}