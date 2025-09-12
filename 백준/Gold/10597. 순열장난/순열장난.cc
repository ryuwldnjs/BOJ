#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int len, n;
vector<int> answer;
vector<bool> used;
bool isAnswer;
string s;
void solve(int idx){
    if(isAnswer) return;
    if(idx == len){
        for(int i:answer) cout<<i<<' ';
        isAnswer = true;
        return;
    }

    //한글자
    int target = stoi(s.substr(idx, 1));
    if(!used[target] && target <= n){
        used[target] = true;
        answer.push_back(target);
        solve(idx+1);
        used[target] = false;
        answer.pop_back();
    }

    if(idx+1 >= len) return;

    //두글자    
    target = stoi(s.substr(idx, 2));
    if(!used[target]  && target <= n){
        used[target] = true;
        answer.push_back(target);
        solve(idx+2);
        used[target] = false;
        answer.pop_back();
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>s;
    len = s.size();
    if(len <= 9) n = len;
    else n = (len-11) / 2 + 10;

    used.resize(n + 1);

    solve(0);




    return 0;
}