#include <iostream>
#include <queue>
using namespace std;

// arr[i] 는 중요도 i+1
struct dock {
    int pri;
    int order;
};

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    while(N--) {

        int A,B; cin >> A >> B;
        queue<dock> q;

        int num = 0;
        //bool test = true;

        for(int i=0; i<A; ++i) {
            int x; cin >> x;
            dock d ;
            d.pri = x;
            d.order = i;
            q.push(d);
        }

        while(1)
        {
            bool test = true;

            int sz = q.size();
            dock target = q.front();
            while(sz--){
            	q.push(q.front());
            	q.pop();
            	if(target.pri < q.front().pri){
            		test = false;
            	//	break;
				}
				
			}
            if (test) {
                int x = q.front().order;
                q.pop();
                ++num;
                if (x == B) {
                    break;
                }
            }
            else {
                dock temp = q.front();
                q.pop();
                q.push(temp);
            }
        }
        cout << num << '\n';
    }
    return 0;
}