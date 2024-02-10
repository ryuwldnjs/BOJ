#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer(arr.begin(), unique(arr.begin(), arr.end()));   
    return answer;
}