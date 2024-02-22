#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> m;
vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    for(int i=0;i<name.size();i++){
        m[name[i]] = yearning[i];
    }
    for(auto pho : photo){
        int tmp = 0;
        for(auto s : pho){
            tmp += m[s];
        }
        answer.push_back(tmp);
    }
    return answer;
}