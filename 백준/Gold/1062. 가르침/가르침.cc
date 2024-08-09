#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getBit(char x){
    return 1<<(x-'a');
}
bool isIncluding(int bigger, int target){ //bigger가 target을 전부 포함하고 있는지
    return (bigger&target) == target;
}
int n,k;
int designated = 0;
vector<int> words;
int MAX = 0;

void makeCombi(char alpha, int cnt, int combi){
    if(alpha == 'z' || cnt >= k){
        int tmp = 0;
        for(int word : words){
            if(isIncluding(combi, word)) tmp++;
        }
        MAX = max(MAX, tmp);
        return;
    }
    if((designated & getBit(alpha+1))){ // 다음 알파벳이 이미 지정된 알파벳 명단에 있을떄
        makeCombi(alpha+2, cnt, combi);
        makeCombi(alpha+2, cnt+1, combi | getBit(alpha+2));
        return;
    }
    else{
        makeCombi(alpha+1, cnt, combi);
        makeCombi(alpha+1, cnt+1, combi | getBit(alpha+1));
    }
    return;
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        string str; cin>>str;
        int word = 0;
        for(char x : str){
            word |= getBit(x);
        }
        words.push_back(word);
    }

  
    int bitA = getBit('a');
    int bitN = getBit('n');
    int bitT = getBit('t');
    int bitI = getBit('i');
    int bitC = getBit('c');
    designated = bitA | bitN | bitT | bitI | bitC;
    makeCombi('a', 5, designated);
    if(k < 5) MAX = 0;
    cout<<MAX;
    return 0;
}