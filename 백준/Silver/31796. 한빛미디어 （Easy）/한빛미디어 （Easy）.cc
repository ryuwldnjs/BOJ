#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,x,answer;
vector<int> books;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;books.push_back(x);
	}
	sort(books.begin(), books.end());
	int start = -1;
	for(int i=0;i<n;i++){
		if(books[i] >= 2*start){
			start = books[i];
			answer++;
		}
	}
	cout<<answer;
	return 0;
}