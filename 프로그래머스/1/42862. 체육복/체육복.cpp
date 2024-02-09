#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    vector<int> have(n+1, 1);
    for(auto x : lost) have[x]--;
    for(auto x : reserve) have[x]++;
    
    for(int i=1;i<=n;i++){
        if(have[i] == 0){
            if(have[i-1] == 2){
                have[i-1]--;
                have[i]++;
            }
            else if(have[i+1] == 2){
                have[i+1]--;
                have[i]++;
            }
            else{
                answer--;
            }
        }
    }
    return answer;
}