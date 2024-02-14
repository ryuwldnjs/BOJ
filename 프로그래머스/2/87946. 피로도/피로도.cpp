#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    sort(dungeons.begin(), dungeons.end());
    do{
        int hp = k;
        int explore = 0;
        for(auto dungeon : dungeons){
            if(hp >= dungeon[0]){
                hp -= dungeon[1];
                explore++;
            }
        }
        answer = max(answer, explore);
    }while(next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}