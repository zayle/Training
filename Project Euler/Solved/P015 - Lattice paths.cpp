#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 22;
long long mp[mx][mx];

void Solve() {
	int i, j;
	mp[0][1] = 1;
	for (i = 1; i < mx; i++) {
		for (j = 1; j < mx; j++) {
			mp[i][j] = mp[i][j - 1] + mp[i - 1][j];
		}
	}
	cout << mp[mx - 1][mx - 1] << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	Solve();
	return 0;
}