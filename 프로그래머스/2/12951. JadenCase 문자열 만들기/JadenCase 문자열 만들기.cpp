#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    for(int i=0;i<s.size();i++){
        if((i==0 || s[i-1]==' ') && 'a' <=s[i]&&s[i]<='z') s[i] -= 32;
        if(i!=0 && s[i-1] != ' ' && 'A' <=s[i]&&s[i]<='Z') s[i] += 32;
    }
    return s;
}