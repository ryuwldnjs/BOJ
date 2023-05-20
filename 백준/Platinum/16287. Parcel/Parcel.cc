#include <iostream>
#include <algorithm>
using namespace std;
int w,n,a[5000+5];
struct stats{
	int a,b;
};
stats weight[800000];
int main(){
	cin>>w>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	
	//sort(a,a+n);
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){		
			if(w-a[i]-a[j]>=0)		
			weight[w-a[i]-a[j]]={i,j};
		}
	}
/*	for(int i=0;i<n;i++){
		if(weight[a[i]].a||weight[a[i]].b||weight[a[i]].c){
			if(weight[a[i]].a!=i && weight[a[i]].b!=i && weight[a[i]].c!=i){
				cout<<"YES";
				return 0;
			}
		}
	}
*/
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int x = weight[ a[i] +a[j]].a;
			int y = weight[a[i]+a[j]].b;
			if(y){
				if(i!=x && i!=y && j!=x && j!=y){
					cout<<"YES";
					return 0;
				}	
			}
		}
	}
	cout<<"NO";
	return 0;
}