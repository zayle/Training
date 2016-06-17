#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

int n, p;

void Solve() {
	int alice, bob, me;
	string answer = "YES";
	alice = (n - 1) / 3;
	bob = alice;
	me = bob;
	if (((n - 1) % 3) > 0) alice++;
	if (((n - 1) % 3) > 1) bob++;
	if ((n - alice) < p) answer = "NO";
	if (p <= bob) answer = "NO";
	cout << answer << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	int c;
	string w;
	cin >> n >> p;
	for (i = 0; i < n; i++) {
		cin >> c >> w;
	}
	Solve();
	return 0;
}