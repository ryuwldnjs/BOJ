#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Fraction{
    int up, down;
    Fraction(int a, int b):up(a), down(b){}
    
    bool operator<(const Fraction& other)const{
        return up*other.down < down*other.up;
    }
};
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int partition(vector<Fraction>& arr, int left, int right){
    int idx = left + rand()%(right-left+1);
    swap(arr[idx], arr[right]);
    Fraction pivot = arr[right];
    for(int i=left;i<right;i++){
        if(arr[i] < pivot){
            swap(arr[left], arr[i]);
            left++;
        }
    }
    swap(arr[left], arr[right]);
    return left;
}
Fraction quickSort(vector<Fraction>& arr, int left, int right, int k){
    if(left < right){
        int pivot = partition(arr, left, right);
        if(pivot == k) return arr[pivot];
        else if(pivot < k) return quickSort(arr, pivot+1, right, k);
        else return quickSort(arr, left, pivot-1, k);
    }
    return arr[left];
}
Fraction findKth(vector<Fraction>& arr, int k){
    return quickSort(arr, 0, arr.size()-1, k);
}

vector<Fraction> arr;
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    arr.push_back({0,1});
    // arr.push_back({1,1});

    int n,k;
    cin>>n>>k;
    if(n>=2) arr.push_back({1,2});    
    for(int i=3;i<=n;i++){
        for(int j=1;j<=i/2;j++){
            if(gcd(i,j)==1){
                arr.push_back({j,i});
            }
        }
    }
    bool isReversed = false;
    if(k>arr.size()){
        k = 2*arr.size() - k;
        isReversed = true;
    }

    Fraction answer = findKth(arr, k-1);
    if(isReversed) cout<<answer.down - answer.up<<" "<<answer.down;
    else cout<<answer.up<<" "<<answer.down;
    // sort(arr.begin(), arr.end());
    // cout<<arr.size()<<endl;
    // for(int i=0;i<arr.size();i++){
    //     cout<<arr[i].up<<"/"<<arr[i].down<<endl;
    // }


    return 0;
}