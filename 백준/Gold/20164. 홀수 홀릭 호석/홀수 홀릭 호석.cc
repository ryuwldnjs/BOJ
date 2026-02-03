#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define INF (int)1e9
struct Info{
    int MIN, MAX;
    
    Info operator<<(Info other){
        MIN = min(MIN, other.MIN);
        MAX = max(MAX, other.MAX);
        return *this;
    }
    Info operator+(Info other){
        MIN += other.MIN;
        MAX += other.MAX;
        return *this;
    }
};



//숫자, 지금까지 홀수 개수
Info solve(string num){
    int len = num.size();
    int odds=0;
    for(int i=0;i<len;i++){
        int val = num[i] - '0';
        if(val % 2 == 1) odds++;
    }

    if(len == 1){
        return {odds, odds};
    }

    if(len == 2){
        int next = num[0]-'0' + num[1]-'0';
        return solve(to_string(next)) + Info{odds, odds};
    }

    //len >= 3
    Info ret = {INF, -INF};
    
    for(int i=1;i<len;i++){
        for(int j=i+1;j<len;j++){
            string a = num.substr(0, i);
            string b = num.substr(i, j-i);
            string c = num.substr(j);
            int next = stoi(a) + stoi(b) + stoi(c);
            ret = ret << solve(to_string(next));
        }
    }
    ret = ret + Info{odds, odds};

    return ret;
}


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    string num;cin>>num;
    Info ret = solve(num);
    
    cout<<ret.MIN<<' '<<ret.MAX;
    return 0;
}