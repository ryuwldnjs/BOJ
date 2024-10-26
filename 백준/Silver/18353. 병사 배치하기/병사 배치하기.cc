#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> lis;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        x *= -1;
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if(it == lis.end()) lis.push_back(x);
        else *it = x;
    }

    cout<<n - lis.size();
    return 0;
}