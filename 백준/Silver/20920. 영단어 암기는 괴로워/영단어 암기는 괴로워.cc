#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string> 
using namespace std;
struct Word{
	string word;
	int freq;
	
	bool operator<(const Word &other)const{
		if(freq != other.freq)
			return freq > other.freq;
		if(word.size() != other.word.size())
			return word.size() > other.word.size();
		return word < other.word;
	}
};

unordered_map<string, int> freq;
int n,m;
vector<Word> words;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		string s;cin>>s;
		if(s.size() < m) continue;
		freq[s]++;
	}
	
	for(auto it = freq.begin(); it!= freq.end(); it++){
		words.push_back({it->first, it->second});
	}
	sort(words.begin(), words.end());
	for(auto w : words){
		cout<<w.word<<'\n';
	}
	return 0;
}