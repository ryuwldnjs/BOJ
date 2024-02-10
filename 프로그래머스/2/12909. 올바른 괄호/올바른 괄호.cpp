#include<string>
#include <iostream>

using namespace std;
int l, r;
bool solution(string s)
{
    for(auto c : s){
        if(c == '(') l++;
        else r++;
        
        if(r > l) return false;
    }
    return l == r;
}