#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int n,a,b;
vector<int> t;
int getTask(int x, int idx){
    int time = 0;
    int task = 0;
    for(int i=0;i<n;i++){
        //idx번째일때 잠 자기
        if(task==idx) time += b*x;

        if(task >= idx){ //잠을 청한 후
            if(time + a-x <= t[i]){
                task++;
                time += a-x;
            }
        }
        else{//잠을  청하기 전
            if(time + a <= t[i]){
                task++;
                time += a;
            }
        }
    }
    return task;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>a>>b;
    t.resize(n);
    for(int i=0;i<n;i++){
        cin>>t[i];
    }

    sort(t.begin(), t.end());

    int answer = 0;
    for(int x=0;x<a;x++){//잠 x만큼 잠
        for(int i=0;i<n;i++){
            answer = max(answer, getTask(x, i));
        }
    }
    cout<<answer;
    return 0;
}