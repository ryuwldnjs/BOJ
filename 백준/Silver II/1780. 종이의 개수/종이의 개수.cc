#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

const int MAX = 3000 + 5;
int graph[MAX][MAX];
int cntArr[3];
int N;
int minus;
int cnt1, zero;
void divide(int x,int y, int size) {
   int s = size / 3;
   bool isSame = true;
   
   if (size == 1) {
      // cout << "사이즈 1 " << "\n";
      if (graph[x][y] == -1) {
         cntArr[0]++;
         return;
      }
      else {
         cntArr[graph[x][y] +1]++;
         return;
      }

   }
// cout << "호출" << " x:" << x << ", y:" << y << "\n";
   for (int i = x; i < x+size; i++) {
      for (int j = y; j < y+size; j++) {
         // cout << "반복" << " i:" << i << ", j:" << j << "\n";
         if (graph[x][y] != graph[i][j]) {
            isSame = false;
            for (int k = 0; k < 3; k++) {for (int r = 0; r < 3; r++) {divide(x + r*s, y + k*s, s);}}// 호출 for
            
            break;
         }//if

      }
      if(isSame==false) break;
   }
   if (isSame == true) {
      if (graph[x][y] == -1) {
         cntArr[0]++;
         return;
      }
      else {
         cntArr[graph[x][y]+1]++;
         return;
      }

   }

}



int main() {
   cin >> N;
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         cin >> graph[i][j];
      }
   }
   divide(0,0,N);
   cout << cntArr[0] << "\n" << cntArr[1] << "\n" << cntArr[2] << "\n";
   

   return 0;
}