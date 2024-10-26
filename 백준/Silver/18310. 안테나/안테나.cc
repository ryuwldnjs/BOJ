#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;
int n;
int main(){
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(), a.end());
    cout<<a[(n-1)/2];
    return 0;
}