#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

set<string> memo;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    string s,p;cin>>s>>p;

    string target;
    int answer = 1;
    for(int i=0;i<p.size();){
        target += p[i];
        if(s.find(target) == string::npos){
            answer++;
            target.clear();
            continue;
        }
        i++;
    }
    cout<<answer;
    return 0;
}