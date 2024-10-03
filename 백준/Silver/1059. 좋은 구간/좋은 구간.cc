#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int l,n, ans;
vector<int> arr;
int main(){
    cin>>l;
    arr.resize(l);
    for(int i=0;i<l;i++){
        cin>>arr[i];
    }
    cin>>n;
    arr.push_back(0);
    arr.push_back(1001);
    sort(arr.begin(), arr.end());

    int idx = lower_bound(arr.begin(), arr.end(), n) - arr.begin();

    int l = arr[idx-1]+1;
    int r = arr[idx]-1;

    // cout << (n - l) * (r - n - 1) - 1;
    // printf("%d %d\n", l,r);
    // printf("%d %d\n", n-l, r-n);

    // x = n-l
    // y = r-n
    // xy + x + y
    // printf("%d %d\n", n-l, r-n);
    // cout<<(n-l) * (r-n) + r-l;
    int ans = (n-l) * (r-n) + r-l;
    cout<< (ans > 0 ? ans : 0);
    return 0;
}