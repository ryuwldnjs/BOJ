#include <bits/stdc++.h>

using namespace std;
map<string, string> parent;
map<string, int> earn;



vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    int n = enroll.size();
    int m = seller.size();
    for(int i=0;i<n;i++){
        parent[enroll[i]] = referral[i];
    }
    parent["-"] = "NULL";
    
    for(int i=0;i<m;i++){
        int remain = amount[i] * 100;
        string now = seller[i];
        while(now != "-" && remain > 0){
            int partial = remain / 10;
            earn[now] += remain - partial;
            remain = partial;
            now = parent[now];
        }
    }    
    
    vector<int> answer;
    for(string e : enroll){
        answer.push_back(earn[e]);
    }
    return answer;
}