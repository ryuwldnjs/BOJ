#include <string>
#include <vector>
#include <map>
#include <stdio.h>
#include <iostream>
using namespace std;
map<string, bool> prefix;
bool solution(vector<string> phone_book) {
    bool answer = true;
    for(string s : phone_book) prefix[s] = true;
    
    for(string s : phone_book){
        for(int i=0;i<s.size();i++){
            string tmp = s.substr(0,i);
            // cout<<tmp<<'\n';
            if(prefix[tmp]) answer = false;
        }
    }
    return answer;
}