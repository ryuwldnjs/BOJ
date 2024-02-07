#include <vector>
// #include <algorithm>
// #include <cstdio>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    
    // int answer = 0;
//     int n = nums.size();
//     sort(nums.begin(), nums.end());
//     // auto tmp = unique(nums.begin(), nums.end());
//     nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
//     answer = min((int)nums.size(), n/2);
//     // printf("%d, %d", )
    set<int> s(nums.begin(), nums.end());
    return min(s.size(), nums.size() / 2);
}