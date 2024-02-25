#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    gems.push_back(gems.back()); //out of bound 방지
    vector<int> answer;
    set<string> s(gems.begin(), gems.end());
    unordered_map<string, int> m; //m[보석] = 해당보석의 개수
    int n = s.size(); //보석 가짓수
    
    int l = 0;
    int r = 0;
    int len = 1e9;
    int cnt = 1; //현재 구간에 포함된 보석들의 가짓수
    m[gems[0]]++;
    while(l <= r && r < gems.size()-1){
        if(cnt == n){
            if(len > r - l){
                len = r - l;
                answer = {l+1,r+1};
            }
            if(--m[gems[l++]] == 0) cnt--;
        }
        else{ //보석찾아 삼만리
            if(m[gems[++r]]++ == 0) cnt++;
        }
    }
    return answer;
}