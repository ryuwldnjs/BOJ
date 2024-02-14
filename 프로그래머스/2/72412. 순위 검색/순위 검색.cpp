#include <bits/stdc++.h>
using namespace std;
string about, AND;
vector<string> tmp(4);
int score;
unordered_map<string, vector<int>> m;

void makeKey(string now, int n){
    if(n == 4) {
        m[now].push_back(score);
        return;
    }
    makeKey(now + about[n], n+1);
    makeKey(now + "-", n+1);
}
void shorten(string s){
    stringstream ss(s);
    about = "";
    ss>>tmp[0]>>tmp[1]>>tmp[2]>>tmp[3]>>score;
    for(string x : tmp) about += x[0];
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for(string s : info){
        shorten(s);
        makeKey("", 0);
    }
    //각 검색옵션 별로 정렬
    for(auto it = m.begin(); it != m.end(); it++){
        sort((*it).second.begin(), (*it).second.end());
    }
        
    for(string s: query){
        stringstream ss(s);
        string q;
        ss>>tmp[0]>>AND>>tmp[1]>>AND>>tmp[2]>>AND>>tmp[3]>>score;
        for(string x : tmp) q += x[0];

        answer.push_back(m[q].end() - lower_bound(m[q].begin(), m[q].end(), score));
    }
    return answer;
}