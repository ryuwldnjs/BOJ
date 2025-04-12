#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
vector<ll> value={0,1,2,3,4,5,6,7,8,9};
vector<vector<ll>> words;
map<char, ll> m;

ll getNum(vector<ll> &word){
    ll res = 0;
    for(ll i=0;i<word.size();i++){
        res *= 10;
        res += value[word[i]];
    }
    return res;
}
ll calc(){
    ll res = 0;
    for(auto word: words){
        res += getNum(word);
    }
    return res;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin>>n;
    int idx = 0;
    for(ll i=0;i<n;i++){
        string str; cin>>str;
        vector<ll> word;
        for(char c: str){
            if(m.count(c) == 0){
                m[c] = idx++;
            }
            word.push_back(m[c]);
        }
        words.push_back(word);
    }

    ll answer = 0;
    do{
        answer = max(answer, calc());
    }while(next_permutation(value.begin(), value.end()));

    cout<<answer;
    return 0;
}