#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    for(auto op : operations){
        stringstream ss(op);
        string command;
        int num;
        
        ss>>command>>num;
        if(command == "I") s.insert(num);
        else if(s.empty()) continue; //비어있을때
        else if(num == 1) // D 1
            s.erase(--s.end());
        else  // D -1
            s.erase(s.begin());
    }
    s.empty() ? answer = {0,0} : answer = {*(--s.end()), *s.begin()};
    return answer;
}