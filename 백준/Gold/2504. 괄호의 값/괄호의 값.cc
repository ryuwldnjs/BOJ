#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    char c;
    int val;
};
string a;
stack<Info> s;
bool isAnswer = true;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>a;
    for(char c: a){
        if(c =='(' || c == '[') s.push({c, 0});
        else{
            int num = 0;
            while(!s.empty() && s.top().c == 'N'){
                num += s.top().val;
                s.pop();
            }
            if(s.empty() || s.top().c=='(' && c==']' || s.top().c=='[' && c==')'){
                isAnswer = false;
                break;
            }
            if(c ==')') num = num? num*2 : 2;
            if(c ==']') num = num? num*3 : 3;
            s.pop();
            s.push({'N', num});
        }
    }
    int answer  =0;
    while(!s.empty()){
        if(s.top().c != 'N') isAnswer = false;
        answer += s.top().val;
        s.pop();
    }

    if(!isAnswer){
        cout<<0;
        return 0;
    }
    cout<<answer;
    return 0;
}