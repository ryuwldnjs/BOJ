#include <bits/stdc++.h>
using namespace std;
bool isAnswer;
string s,t;
void solve(string str){
    if(str == s) isAnswer = true;
    if(isAnswer) return;

    if(str.back() == 'A') solve(str.substr(0, str.size()-1));
    if(str.front() == 'B') {
        reverse(str.begin(), str.end());
        str.pop_back();
        solve(str);
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>s>>t;
    solve(t);

    cout<<isAnswer;
    return 0;
}