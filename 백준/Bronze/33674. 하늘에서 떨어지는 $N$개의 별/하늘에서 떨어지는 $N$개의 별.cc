#include <iostream>
#include <algorithm>
using namespace std;
int n,d,k;
int MAX = -1;
int answer;
int main(){
    cin>>n>>d>>k;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        MAX = max(MAX, x);
    }
    int now = 0;
    for(int i=0;i<d;i++){
        if(now + MAX > k){
            answer++;
            now = 0;
        }
        now += MAX;
    }
    cout<<answer;
    return 0;
}