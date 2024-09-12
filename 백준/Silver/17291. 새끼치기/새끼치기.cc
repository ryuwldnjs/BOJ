#include <iostream>
using namespace std;
int arr[25], born[25];
int n;
int main(){
    cin>>n;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    arr[4] = 7;
    born[1] = 1;
    born[2] = 1;
    born[3] = 2;
    born[4] = 4;
    for(int i=5;i<=n;i++){
        arr[i] = 2*arr[i-1];
        if(i%2 == 0) arr[i] -= born[i-3] + born[i-4];
        born[i] = arr[i-1];
    }
    cout<<arr[n];
    return 0;
}