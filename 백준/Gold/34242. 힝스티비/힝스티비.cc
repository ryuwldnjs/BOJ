#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;
int prefix[300000+5];
int suffix[300000+5];
string PLUS = "+^+";
string MINUS = "-^-";

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    string str;cin>>str;
    int n = str.size();

    for(int i=2;i<n;i++){
        prefix[i] = prefix[i-1];
        string target = str.substr(i-2,3);
        if(target == PLUS) prefix[i]++;
        else if(target == MINUS) prefix[i]--;
        // cout<<target<<'\n';
    }


    for(int i=n-3;i>=0;i--){
        suffix[i] = suffix[i+1];
        string target = str.substr(i,3);
        if(target == PLUS) suffix[i]++;
        else if(target == MINUS) suffix[i]--;
    }


    int answer = -INF;
    //i번째 글자를 없앨떄
    for(int i=0;i<n;i++){
        int ret = 0;
        if(i > 0) ret += prefix[i-1];
        if(i < n-1) ret += suffix[i+1];

        //i가 사라지고 새로 생긴 조합들
        if(i-2>=0 && i+1<n){
            string tmp;
            tmp.push_back(str[i-2]);
            tmp.push_back(str[i-1]);
            tmp.push_back(str[i+1]);

            if(tmp == PLUS) ret++;
            else if(tmp == MINUS) ret--;
        }

        if(i-1>=0 && i+2<n){
            string tmp;
            tmp.push_back(str[i-1]);
            tmp.push_back(str[i+1]);
            tmp.push_back(str[i+2]);
            if(tmp == PLUS) ret++;
            else if(tmp == MINUS) ret--;
        }
        answer = max(answer, ret);
    }

    answer = max(answer, prefix[n-1]);
    cout<<answer;
    return 0;
}