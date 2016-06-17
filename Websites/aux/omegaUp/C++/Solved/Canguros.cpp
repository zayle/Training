#include <fstream>
#include <iostream>
#include <queue>
using namespace std;
// fstream fs("in.txt", fstream::in);

int c, n;
queue<int> children;

void Solve() {
	int i, aux;
	char action;
	for (i = 0; i < n; i++) {
		cin >> action;
		if (action == 'N') {
			cin >> aux;
			children.push(aux);
		} else if (action == 'A') {
			c -= (1 + children.front());
			children.pop();
		} else if (action == 'C') {
			cout << children.size() << '\n';
		} else if (action == 'R') {
			cout << c << '\n';
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	cin >> c >> n;
	Solve();
	return 0;
}