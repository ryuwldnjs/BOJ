#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> answer(27);
int arr[27];

string getCourse(int n){ //비트마스크를 문자열로 변환
    string course = "";
    for(int i=0;i<26;i++){
        if(n & (1<<i)) course += 'A' + i;
    }
    return course;
}
int getBit(string s){ //문자열을 비트마스크로 변환
    int tmp = 0;
    for(auto c: s) tmp += 1<<(c - 'A');
    return tmp;
}
int getBitCnt(int n){//켜져있 비트 개수 반환
    int cnt = 0;
    while(n){
        if(n&1) cnt++;
        n >>= 1;
    }
    return cnt;
}

void solve(int order, int k, vector<string> &orders){
    int bits = getBitCnt(order);
    if(bits > 10) return;
    
    if(k == 26){
        int cnt = 0; // 해당 조합을 포함하는 주문들 개수
        for(int i=0;i<orders.size();i++){
            if((getBit(orders[i]) & order) == order) cnt++;
        }
        
        if(arr[bits] < cnt && cnt >= 2){ // 더 많이 해당되는 조합 발견
            arr[bits] = cnt;
            answer[bits] = vector<int>(1, order);
        }
        else if(arr[bits] == cnt && cnt >= 2){
            answer[bits].push_back(order);
        }

        return;
    }
    solve(order | (1<<k), k+1, orders);
    solve(order, k+1, orders);
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answerString;
    solve(0, 0, orders);

    for(int cnt : course){
        for(int j=0;j<answer[cnt].size();j++){
            answerString.push_back(getCourse(answer[cnt][j]));
        }
    }
    sort(answerString.begin(), answerString.end());
    return answerString;
}