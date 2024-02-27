#include <bits/stdc++.h>
using namespace std;
int solution(int n) {
    long fibo[3] = {0,1,1};
    for(int i=3;i<=n;i++) fibo[i%3] = (fibo[(i+2)%3] + fibo[(i+1)%3]) % 1234567;
    return fibo[n%3];
}