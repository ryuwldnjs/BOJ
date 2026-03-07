#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<char> s;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    string str; cin>>str;

    for(char c: str){
        s.push_back(c);

        int n = s.size();
        while(n >= 4 && s[n-4]=='P' && s[n-3]=='P' && s[n-2]=='A' && s[n-1]=='P'){
            s.pop_back();
            s.pop_back();
            s.pop_back();
            n = s.size();
        }
        
    }


    if(s.size() == 1 && s[0] == 'P') cout<<"PPAP";
    else cout<<"NP";
    return 0;
}