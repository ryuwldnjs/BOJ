#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll getIdx(string s){
    ll idx = 0;
    for(char c: s){
        idx *= (ll)26;
        idx += (ll)c - 'a' + 1;
    }
    return idx;
}

string getStr(ll idx){
    string ret = "";
    // idx--;
    while(idx){
        ret += (ll)(idx-1)%26 + 'a';
        idx = (idx-1)/26;
    }
    
    reverse(ret.begin(), ret.end());
    return ret;
}

string solution(long long n, vector<string> bans) {
    string answer = "";
    sort(bans.begin(), bans.end(), [](string a, string b){
        if(a.size() == b.size()) return a < b;
        return a.size() < b.size();
    });
    // for(string s: bans) cout<<s<<'\n';
    
    for(string ban : bans){
        if(getIdx(ban) <= n) n++;
    }
    
    answer = getStr(n);
    
    return answer;
}