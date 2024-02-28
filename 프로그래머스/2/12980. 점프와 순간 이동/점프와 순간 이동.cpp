#include <bits/stdc++.h>
using namespace std;

int solution(int n)
{
    int answer = 0;
    while(n){
        if(n&1) answer++;
        n >>= 1;
    }
    return answer;
}