#include <string>
#include <vector>

using namespace std;
int calculateBits(int n){
    int cnt = 0;
    while(n){
        if(n%2) cnt++;
        n /= 2;
    }
    return cnt;
}
int solution(int n) {
    int Bits = calculateBits(n);
    for(int i=n+1;i<=2000000; i++){
        if(calculateBits(i) == Bits) return i;
    }
    return n;
}