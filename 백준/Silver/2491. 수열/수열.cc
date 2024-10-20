#include <iostream>
#include <vector>
using namespace std;
int n, MAX=1;
vector<int> arr(100000+5), increasing(100000+5,1), decreasing(100000+5,1);
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


    for(int i=1;i<n;i++){
        if(arr[i-1] <= arr[i]) increasing[i] = increasing[i-1] + 1;
        if(arr[i-1] >= arr[i]) decreasing[i] = decreasing[i-1] + 1;

        MAX = max(MAX, max(increasing[i], decreasing[i]));
    }
    cout<<MAX;
    return 0;
}