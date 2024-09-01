#include <iostream>
using namespace std;
using ll=long long;
ll n;
ll psum, answer;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        ll x; cin>>x;
        
        if(-psum + x > 0){ // 앞줄서는게 뒷줄서는것보다 그리디 하게 좋을때
            answer = max(answer, -psum + x);
        }
        psum += x;

    }
    cout<<answer;
    return 0;
}