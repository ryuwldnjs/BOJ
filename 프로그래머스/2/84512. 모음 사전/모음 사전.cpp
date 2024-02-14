#include <bits/stdc++.h>
using namespace std;

int weight[] = {781,156,31,6,1};
string alpha = "AEIOU";

int solution(string word) {
    int answer = 0;
    
    for(int i=0;i<word.size();i++){
        for(int j=0;j<alpha.size();j++){
            if(word[i] == alpha[j]) answer += j * weight[i] + 1;
        }
    }
    return answer;
}