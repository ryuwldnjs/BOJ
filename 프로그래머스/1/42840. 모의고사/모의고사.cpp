#include <bits/stdc++.h>

using namespace std;
int score[3];
int a[10] = {1, 2, 3, 4, 5};
int b[10] = {2, 1, 2, 3, 2, 4, 2, 5};
int c[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    for(int i=0;i<answers.size();i++){
        if(a[i%5] == answers[i]) score[0]++;
        if(b[i%8] == answers[i]) score[1]++;
        if(c[i%10] == answers[i]) score[2]++;
    }
    int MAX = *max_element(score, score+3);
    for(int i=0;i<3;i++) if(score[i] == MAX) answer.push_back(i+1);
    return answer;
}