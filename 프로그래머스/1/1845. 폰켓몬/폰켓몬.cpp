#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    // auto tmp = unique(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    answer = min((int)nums.size(), n/2);
    // printf("%d, %d", )
    return answer;
}