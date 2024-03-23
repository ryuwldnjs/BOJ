#include <iostream>
using namespace std;
struct Info{
	long long x, y;
};

//점 a,b,c순으로 회전방향 판단 
int CCW(Info a, Info b, Info c){
	//행렬식으로 판단 (신발끈공식) 
	long long op = a.x*b.y + b.x*c.y + c.x*a.y - (a.y*b.x + b.y*c.x + c.y*a.x);
	if(op > 0) return 1;
	else if(op == 0) return 0;
	return -1;
}

int main(){
	Info P1,P2,P3,P4;
	long long a,b,c,d;
	cin>>a>>b>>c>>d;
	P1 = {a,b};
	P2 = {c,d};

	cin>>a>>b>>c>>d;
	P3 = {a,b};
	P4 = {c,d};
	
	if(CCW(P1, P2, P3) * CCW(P1, P2, P4) < 0 && CCW(P3,P4,P1) * CCW(P3,P4,P2) < 0)
		cout<<1;
	else cout<<0; 
	return 0;
}