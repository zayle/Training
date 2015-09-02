#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const long long mod = 9999959999;
long long nodes[1001][2001];

long long Solve(int l, int s) {
	if (l == 0) {
		return (s + 1);
	} else {
		if (nodes[l][s] > 0) {
			return nodes[l][s];
		} else {
			long long a = 0, b = 0, c;
			a = Solve((l - 1), (s + 1));
			if (s > 0) b = Solve(l, (s - 1));
			c = (a + b + 1) % mod;
			nodes[l][s] = c;
			return c;
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	int l, s;
	while (true) {
		cin >> l >> s;
		if ((l == 0) && (s == 0)) break;
		cout << Solve(l, s) << '\n';
	}
	return 0;
}