#include <iostream>
#include <string> 
#include <algorithm>
#include <vector>
using namespace std;
int l,r;
char arr[20];
vector<string> answers;
bool isVowel(char c){
	return c=='a' || c=='i' || c=='u' || c=='e' || c=='o';
}
void solve(int idx, int cnt, bool check[]){
	if(cnt == l){
		string answer;
		int vowel=0,consonant=0;
		for(int i=0;i<r;i++){
			if(check[i]){
				answer += arr[i];
				if(isVowel(arr[i])) vowel++;
				else consonant++;
			}
		}
		if(vowel >= 1 && consonant >= 2){
			sort(answer.begin(), answer.end());
			answers.push_back(answer);
		}
		return;
	}
	if(idx == r) return;
	
	
	check[idx] = true;
	solve(idx + 1, cnt+1, check);
	check[idx] = false;
	solve(idx + 1, cnt, check);
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>l>>r;
	for(int i=0;i<r;i++){
		cin>>arr[i];
	}
	bool check[20]={};
	solve(0,0,check);
	sort(answers.begin(), answers.end());
	for(auto &s : answers){
//		string tmp = s;
//		sort(tmp.begin(), tmp.end());
		
		cout<<s<<'\n';
	}
	return 0;
} 