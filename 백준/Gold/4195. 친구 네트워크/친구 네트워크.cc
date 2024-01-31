#include <iostream>
#include <string>
#include <map>
using namespace std;
string a, b;
int parent[200000 + 5];
map<string, int> network;

int find(int n) {
	if (parent[n] < 0) return n;
	return parent[n] = find(parent[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		parent[b] += parent[a];
		parent[a] = b;
	}
	cout << -parent[b] << '\n';//root노드에 들어있는 음수값==컴포넌트의 노드개수
}


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		fill(parent, parent + 2*n+1, -1);
		network = map<string, int>();
		int cnt = 1;//각 이름별 number
		
		for (int i = 0; i<n; i++) {
			cin >> a >> b;
			if (!network[a]) network[a] = cnt++;
			if (!network[b]) network[b] = cnt++;
			merge(network[a], network[b]);
		}
	}
	return 0;
}