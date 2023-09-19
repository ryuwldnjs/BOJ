#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
     answer[1] = 1000000000;   
    int l=0, r=0;
    int sum = sequence[0];
    while(l<=r && r<sequence.size()){
        if(sum < k){
            sum += sequence[++r];
        }
        else if(sum > k){
            sum -= sequence[l++];
        }
        else{
            if(answer[1] - answer[0] > r-l){
                answer[0] = l;
                answer[1] = r;
            }
            sum -= sequence[l++]; 
        }
    }
    
    return answer;
}