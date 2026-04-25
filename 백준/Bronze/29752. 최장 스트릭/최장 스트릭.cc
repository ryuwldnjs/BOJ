#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int cnt=0,answer=0;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        cnt++;
        if(x == 0){
            cnt = 0;
        }
        answer = max(answer, cnt);
        // px = x;
    }
    cout<<answer;
    return 0;
}