#include <string>
#include <vector>

using namespace std;
int solve(int idx, int sum, vector<int> & numbers, int target){
    if(idx == numbers.size()){
        if(sum == target) return 1;
        return 0;
    }
    
    return solve(idx+1, sum + numbers[idx], numbers, target)
        +solve(idx+1, sum - numbers[idx], numbers, target);
}
int solution(vector<int> numbers, int target) {
    return solve(0, 0, numbers, target);
}