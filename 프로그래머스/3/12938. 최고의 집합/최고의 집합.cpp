#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int s) {
    int value = s / n;
    s %= n;
    vector<int> answer(n, value);
    
    for(int i=0;i<s;i++) answer[i]++;
    sort(answer.begin(), answer.end());
    
    if(answer[0] == 0) answer = vector<int>(1,-1);
    return answer;
}