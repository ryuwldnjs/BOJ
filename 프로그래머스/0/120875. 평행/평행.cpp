#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    sort(dots.begin(), dots.end());
    do{
        double m1 = (double)(dots[0][1]-dots[1][1]) / (dots[0][0]-dots[1][0]);
        double m2 = (double)(dots[2][1]-dots[3][1]) / (dots[2][0]-dots[3][0]);
        if(m1 == m2) { 
        answer = 1;
        }
    }while(next_permutation(dots.begin(), dots.end()));
    return answer;
    
}