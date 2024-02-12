#include <bits/stdc++.h>
using namespace std;
vector<int> number(10);
int n, answer;

bool isPrime(int num){
    if(num == 1) return false;
    for(int i=2;i*i<=num;i++){
        if( num%i == 0) return false;
    }
    return true;
}
void findPrime(int num){
    if(isPrime(num)) answer++;
    
    for(int i=0;i<=9;i++){
        if(number[i] == 0) continue;
        number[i]--;
        findPrime(10*num + i);
        number[i]++;
    }
}

int solution(string numbers) {
    n = numbers.size();
    for(char c: numbers) number[c - '0']++;
    
    for(int i=1;i<=9;i++){
        if(number[i] == 0) continue;
        number[i]--;
        findPrime(i);
        number[i]++;
    }
    return answer;
}