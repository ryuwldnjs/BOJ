#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

string s, answer;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        char c;cin>>c;
        s.push_back(c);
    }
    int l=0, r=n-1;
    while(l<=r){
        int l_idx = l;
        int r_idx = r;
        while(l_idx+1 < r_idx && s[l_idx] == s[r_idx]){
            l_idx++;
            r_idx--;
        }

        if(s[l_idx] <= s[r_idx]){
            answer.push_back(s[l++]);
        }
        else if(s[l_idx] > s[r_idx]){
            answer.push_back(s[r--]);
        }
    }

    // cout<<answer;
    for(int i=0;i<answer.size();i++){
        if(i && i%80==0) cout<<'\n';
        cout<<answer[i];
    }
    return 0;
}