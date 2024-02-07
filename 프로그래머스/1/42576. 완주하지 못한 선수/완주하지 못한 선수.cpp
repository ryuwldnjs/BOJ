#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    for(auto x : participant) m[x]++;
    for(auto x : completion) m[x]--;
    for(auto x : m) if(x.second != 0) answer = x.first;
    return answer;
}