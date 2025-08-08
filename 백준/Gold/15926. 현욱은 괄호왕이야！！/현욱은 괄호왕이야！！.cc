#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;


vector<int> s={-1};
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;

    int answer = 0;
    for(int i=0;i<n;i++){
        char c; cin>>c;
        if(c == '(') s.push_back(i);
        else{
            s.pop_back();
            //잘못된 괄호
            if(s.empty()) s.push_back(i);
            else{
                answer = max(answer, i - s.back());
            }
        }
    }
    cout<< answer;
    return 0;
}