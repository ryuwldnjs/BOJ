#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> m;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for(auto cloth : clothes) m[cloth[1]]++;
    
    for(auto it = m.begin(); it != m.end(); it++)
        answer *= it->second + 1;
    return answer - 1;
}