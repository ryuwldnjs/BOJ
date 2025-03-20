#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int timeToInt(string time){
    int hour = stoi(time.substr(0,2));
    int minute = stoi(time.substr(3,2));
    return hour*60 + minute;
}
string intToTime(int minute){
    int hour = minute / 60;
    minute %= 60;
    char buf[6];
    sprintf(buf, "%02d:%02d", hour, minute);
    string result = buf;
    return result;
}

string solution(int n, int t, int m, vector<string> timetable) {
    int start_time = timeToInt("09:00");
    
    vector<int> times;
    for(string time: timetable) times.push_back(timeToInt(time));
    sort(times.begin(), times.end());
    
    vector<vector<int>> partition(n);
    
    int target = 0;
    //각 셔틀별로 탑승 인원 체크
    for(int i=0;i<n;i++){
        int upto = start_time + i*t;
        
        for(;target<times.size();target++){
            if(times[target] > upto) break;
            if(partition[i].size() >= m) break;
            partition[i].push_back(times[target]);
        }
    }
    
    int answer;
    
    //막차 자리 있으면 걍 타면 됨
    if(partition[n-1].size() < m){
        answer = start_time + (n-1) * t;
    }
    //막차 자리없으면, 젤 늦는놈보다 1분 일찍 도착하면 됨
    else{
        answer = partition[n-1].back() - 1;
    }
    
    return intToTime(answer);
}