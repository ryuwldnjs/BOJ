#include <string>
#include <vector>
#include <iostream>

using namespace std;
int changeCost(char x){
    return min(x - 'A', 'A' - x + 26);
}
int cost[25], sum;
int solution(string name) {
    for(int i=0;i<name.size();i++){
        cost[i] = changeCost(name[i]);
        sum += cost[i];
        // cout<<cost[i]<<' ';
    }
    
    
    int answer = 2e9;
    for(int i=0;i<name.size();i++){
        int right = i;
        int left = i+1;
        while(cost[right]==0 && right>0) right--;
        while(cost[left]==0 && left < name.size()-1) left++;
        
        int moveCost = min(2*right + name.size() - left, 2*(name.size() - left) + right);
        cout<<right<<' '<<left<<'\n';
        answer = min(answer, moveCost);
    }
    
    answer += sum;
    return answer;
}