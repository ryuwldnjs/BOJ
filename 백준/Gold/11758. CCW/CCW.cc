#include <iostream>
using namespace std;
int cross_product(int x1, int y1, int x2, int y2){
	return x1*y2 - x2*y1;
}
int x1,y1,x2,y2,x3,y3;
int main(){
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	int result = cross_product(x2-x1, y2-y1, x3-x2, y3-y2);
	//벡터의 외적을 이용.
	// A X B = AB sint, 이때 시계방향이면 t < pi이므로 양수가 나온다. 
	if(result>0)
		cout<<1;
	else if(result < 0 )
		cout<<-1;
	else
		cout<<0;
	return 0;
}