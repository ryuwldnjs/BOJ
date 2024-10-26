#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a,b;
int n;
int main(){
    cin>>n;
    a.resize(n);
    b.resize(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    //b쪽에 몰아줄거임
    a[n-1] += b[n-2];
    b[n-1] += a[n-2];
    a[n-2] = b[n-2] = 0;

    if(a.back() > b.back()) swap(a,b);
    for(int i=0;i<n-2;i++){
        if(a[i] >= b[i]){
            a[n-1] += b[i];
            b[n-1] += a[i];
        }
        else{
            a[n-2] += b[i];
            b[n-2] += a[i];  
        }
    }
    a[n-1] += b[n-2];
    b[n-1] += a[n-2];
    int answer = b[n-1] - a[n-1];
    cout<<answer;
    return 0;
}