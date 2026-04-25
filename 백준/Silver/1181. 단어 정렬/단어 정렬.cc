#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<stdio.h>
using namespace std;
#include <iostream>
#include <string>
#include <map>
using namespace std;
string x[20005];
int L[20005];
int R[20005];
int index[20005];

void merge(string arr[], int index[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    for (i = 0; i < n1; i++)
        L[i] = index[l + i];
    for (j = 0; j < n2; j++)
        R[j] = index[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (arr[L[i]].length() < arr[R[j]].length()) {
            index[k] = L[i];
            i++;
        }
        else if(arr[L[i]].length() > arr[R[j]].length()){
            index[k] = R[j];
            j++;
        }
        else {
            if (arr[L[i]] == arr[R[j]]) {
                index[k] = L[i];
                R[j] = L[i];
                i++;
            }
            else if (arr[L[i]] > arr[R[j]]) {
                index[k] = R[j];
                j++;
            }
            else {
                index[k] = L[i];
                i++;
            }
        }
        k++;
    }
    while (i < n1) {
        index[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        index[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(string arr[], int index[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, index, l, m);
        mergeSort(arr, index, m + 1, r);
        merge(arr, index, l, m, r);
    }
}

map<string, int> check;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i];
        index[i] = i;
    }
    mergeSort(x, index, 0, N - 1);
    for (int i = 0; i < N; i++) {
        if (i > 0 && check[x[index[i]]]) continue;
        cout << x[index[i]] << '\n';
        check[x[index[i]]] =1;
    }
}