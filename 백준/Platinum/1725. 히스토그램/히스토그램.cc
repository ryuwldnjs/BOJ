#include <iostream>
#include <stack>
#include <vector>
using namespace std;
using pii=pair<int,int>;
stack<pii> s; // [val,idx] 모노톤 스택
vector<int> arr;
int n, answer;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        arr.push_back(x);
    }
    arr.push_back(0);


    for(int i=0;i<arr.size();i++){
        int MIN = 1e9;
        while(!s.empty() && s.top().first >= arr[i]){ // 스택내부는 증가수열
            int val = s.top().first;
            int idx = s.top().second;
            s.pop();

            if(!s.empty()){
                idx = s.top().second + 1;
            }

            MIN = min(MIN, val);
            answer = max(answer, MIN * (i - idx));
        }
        if(s.empty()) answer = max(answer, MIN * i);
        
        s.push({arr[i], i});
        // printf("%d ", answer);
    }

    cout<<answer;
    return 0;
}