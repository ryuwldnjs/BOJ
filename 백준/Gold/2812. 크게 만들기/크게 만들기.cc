#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n,k;
vector<int> num;

void solve(){
    //모노톤 내림차순으로 유지되어야함
    //매번 출력은 front(=가장 큰 값)
    deque<int> dq;

    for(int i=0; i<n; i++){
        while(!dq.empty() && dq.back() < num[i]){
            dq.pop_back();
        }
        dq.push_back(num[i]);

        //출력부
        if(i>=k){
            cout<<dq.front();
            dq.pop_front();
        }
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        char x; cin>>x;
        num.push_back(x - '0');
    }
    solve();
    return 0;
}