#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int visited[200000 + 5];
vector<int> arr[200000 + 5];
queue <pair<int, int> > q;
int cnt[200000 + 5], cnt2[200000 + 5];
int n, m, x;
int main() {
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   cin >> n;

   fill(visited, visited + n + 1, -1);
   for (int i = 1; i <= n; i++) {
      while (true) {
         cin >> x;
         if (x == 0) break;
         arr[i].push_back(x);
         cnt[x]++; //연결된 노드 개수 
      }
   }


   cin >> m;
   for (int i = 0; i<m; i++) {
      cin >> x;
      q.push({ x, 0 });
      visited[x] = 0;
   }

   while (!q.empty()) {
      int now = q.front().first;
      int dist = q.front().second;
      q.pop();

      for (int i = 0; i<arr[now].size(); i++) {
         int next = arr[now][i];
         if (visited[next] != -1) continue; //이미 감염 됐으면 패스

         cnt2[next]++;
         if (cnt2[next] >= (cnt[next] + 1) / 2) { //감염 가능 조건 충족 
            visited[next] = dist + 1;
            q.push({ next, dist + 1 });

         }
      }
   }

   for (int i = 1; i <= n; i++) printf("%d ", visited[i]);
   return 0;
}