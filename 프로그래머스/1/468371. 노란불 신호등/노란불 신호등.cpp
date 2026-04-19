#include <string>
#include <vector>

using namespace std;
bool isYellow(vector<vector<int>> &signals, int t){
    for(vector<int> signal : signals){
        int n = signal[0] + signal[1] + signal[2];
        int time = (t-1) % n + 1;
        if(signal[0] >= time || time > signal[0] + signal[1]) return false;
    }
    return true;
}

int solution(vector<vector<int>> signals) {
    int answer = -1;
    
    for(int i=1;i<10000000;i++){
        if(isYellow(signals, i)) return i;
    }
    return answer;
}