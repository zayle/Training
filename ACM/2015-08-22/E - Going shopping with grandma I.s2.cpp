#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int lMax = 1001, sMax = 2001;
const long long mod = 9999959999;
long long nodes[lMax][sMax + 1];

long long Solve() {
	int l, s;
	for (l = 0; l < lMax; l++) {
		for (s = 0; s < sMax; s++) {
			nodes[l][s] = 1;
			if (l > 0) nodes[l][s] += nodes[l - 1][s + 1];
			if (s > 0) nodes[l][s] += nodes[l][s - 1];
			nodes[l][s] %= mod;
		}	
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	int l, s;
	Solve();
	while (true) {
		cin >> l >> s;
		if ((l == 0) && (s == 0)) break;
		cout << nodes[l][s] << '\n';
	}
	return 0;
}