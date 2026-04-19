#include <bits/stdc++.h>
using namespace std;
struct Info{
    string str;
    int l,r; // 인덱스
};


vector<Info> split(string s){
    stringstream ss(s);
    string word;
    vector<Info> words;
    
    int last = 0; while(s[last] == ' ') last++;
    
    while(ss >> word){
        int l = last;
        int r = l + word.size() - 1;
        words.push_back({word, l, r});
        last = r+2;
        // cout<<word<<l<<r<<'\n';
    }
    return words;
}

int isCovered(Info word, vector<int> range){
    if(range[1] < word.l) return -1; // 다음 range로 검사해야함
    if(word.r < range[0]) return 0;
    return 1;
}

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    vector<Info> words = split(message);
    
    set<string> seen;
    vector<string> banned;
    int idx=0; // 현재 스포 range;
    for(Info word: words){
        while(isCovered(word, spoiler_ranges[idx]) == -1 && idx<spoiler_ranges.size()-1)
            idx++;
            
        // cout<<idx<<' '<<isCovered(word, spoiler_ranges[idx])<<'\n';
        if(isCovered(word, spoiler_ranges[idx]) == 1) banned.push_back(word.str);
        else seen.insert(word.str);
    }
    
    for(string word: banned){
        // cout<<word<<'\n';
        if(seen.count(word)) continue;
        seen.insert(word);
        answer++;
    }
    
    return answer;
}