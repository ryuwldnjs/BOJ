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

//k-th찾기 퀵정렬 기반
// int partition(vector<Fraction>& arr, int left, int right){
//     int idx = left + rand()%(right-left+1);
//     swap(arr[idx], arr[right]);
//     Fraction pivot = arr[right];
//     for(int i=left;i<right;i++){
//         if(arr[i] < pivot){
//             swap(arr[left], arr[i]);
//             left++;
//         }
//     }
//     swap(arr[left], arr[right]);
//     return left;
// }
// Fraction quickSort(vector<Fraction>& arr, int left, int right, int k){
//     if(left < right){
//         int pivot = partition(arr, left, right);
//         if(pivot == k) return arr[pivot];
//         else if(pivot < k) return quickSort(arr, pivot+1, right, k);
//         else return quickSort(arr, left, pivot-1, k);
//     }
//     return arr[left];
// }
// Fraction findKth(vector<Fraction>& arr, int k){
//     return quickSort(arr, 0, arr.size()-1, k);
// }


vector<Fraction> arr={{0,1}};
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    //Reafy수열은 유사 좌우대칭이므로, 절반만 구하기
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i/2;j++){
            if(gcd(i,j)==1){
                arr.push_back({j,i});
            }
        }
    }

    //절반만 구하고 상수커팅...
    bool isReversed = false;
    if(k>arr.size()){
        k = 2*arr.size() - k;
        isReversed = true;
    }


    //n번째 수 찾는 라이브러리 ㅋㅋ
    nth_element(arr.begin(), arr.begin()+k-1, arr.end());
    Fraction answer = arr[k-1];
    if(isReversed) cout<<answer.down - answer.up<<" "<<answer.down;
    else cout<<answer.up<<" "<<answer.down;
    return 0;
}