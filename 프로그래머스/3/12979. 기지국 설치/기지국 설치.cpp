#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int pre = 0;
    int answer = 0;
    for(int &s : stations) s -= w; //기지국 전파 기준점 재설정
    
    for(int &s : stations){
        while(pre < s - 1){
            answer++;
            pre += 2*w + 1;
        }
        pre = s + 2*w;
    }
    while(pre < n){
            answer++;
            pre += 2*w + 1;
        }
    return answer;
}