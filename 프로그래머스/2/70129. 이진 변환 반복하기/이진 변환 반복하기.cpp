#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer = {1, 0};
    int &zero = answer[1];
    int len = s.size();
    for(char c : s){
        if(c == '0') zero++;
    }
    len = len - zero;
    
    while(len > 1){
        int tmp = len;
        int one = 0;
        while(tmp){
            if(tmp & 1) one++;
            else zero++;
            tmp >>= 1;
        }
        len = one;
        answer[0]++;
    }
    return answer;
}