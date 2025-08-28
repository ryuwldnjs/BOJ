#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define OPEN '('
#define CLOSE ')'
#define NUM 'N'
struct Info{
    char type;
    int val;
};
stack<Info> s;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    string str;cin>>str;

    for(int i=0;i<str.size();i++){
        if(str[i] != OPEN && str[i] != CLOSE) s.push({NUM, 1});
        else if(str[i] == OPEN){
            int rate = str[i-1] - '0';
            s.pop();
            s.push({OPEN, rate});
        }
        else if(str[i] == CLOSE){
            int val = 0;
            while(s.top().type != OPEN){
                val += s.top().val;
                s.pop();
            }
            val *= s.top().val;
            s.pop();
            s.push({NUM, val});
        }
    }

    int answer = 0;
    while(!s.empty()){
        answer += s.top().val;
        s.pop();
    }

    cout<<answer;
    return 0;
}