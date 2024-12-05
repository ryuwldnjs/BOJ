#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int l,n, ans;
vector<int> arr;

//결정: 연료 val으로 로봇을 이동시킬때, 해결이 가능한가?
bool able(int val){
    vector<int> left(n, -1), right(n, -1);
    int prev = arr.front();
    //왼쪽 -> 오른쪽
    for(int i=0;i<arr.size(); i++){
        int remain = val; //현재 로봇의 남은 연료량
        if(prev < arr[i]) remain -= arr[i] - prev; //이전로봇이 폐급이라, 앞으로 다가가줘야함
        if(remain <= 0) break; //이전로봇이 너무 폐급이라, 바통터치도 실패함
        prev = min(prev+remain, arr[i]+remain);//남은 연료로 다시 이동
        left[i] = prev;
    }

    prev = arr.back();
    //오른쪽 -> 왼쪽
    for(int i=arr.size()-1;i>=0; i--){
        int remain = val; //현재 로봇의 남은 연료량
        if(arr[i] < prev) remain -= prev - arr[i]; //이전로봇이 폐급이라, 뒤로 다가가줘야함
        if(remain <= 0) break; //이전로봇이 너무 폐급이라, 바통터치도 실패함
        prev = max(prev-remain, arr[i]-remain);//남은 연료로 다시 이동        
        right[i] = prev;
    }

    for(int i=0;i<arr.size()-1;i++){
        if(left[i] == -1 || right[i+1] == -1) continue;
        if(left[i] >= right[i+1]) return true;
    }
    
    return false;
}
int main(){
    cin>>l>>n;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=0, r=2*1000000;
    for(int i=0;i<100;i++){
        int mid = (l+r) / 2;
        if(able(mid)) r = mid;
        else l = mid;
    }
    if(able(l)) cout<<l;
    else cout<<r;
    return 0;
}