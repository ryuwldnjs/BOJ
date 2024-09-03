#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, answer;
vector<int> arr;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x; 
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end(), greater<int>());

    for(int i=0;i<n;i++){
        if(i%3 == 2) continue;
        answer += arr[i];
        // printf("%d ", arr[i]);
    }
    cout<<answer;
    return 0;
}