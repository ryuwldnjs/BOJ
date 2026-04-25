#include <bits/stdc++.h>
using namespace std;

string arr[1000];
int n, zero;

int cmp(string &a, string &b) {
	string p = a+b;
	string q = b+a;
	int sz = p.size();
	
	for(int i=0;i<sz; i++){
		if(p[i] != q[i]) return p[i] > q[i];
	}
	return false;
}


int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    if(arr[i] != "0") zero = 1;
  }
  sort(arr, arr + n, cmp);
  
  if(!zero) cout << "0";
  else for(int i = 0; i < n; i++) cout << arr[i];
}