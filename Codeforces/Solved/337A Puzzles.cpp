#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 50;
int pieces[mx];
int n, m;

void LoadPieces() {
	int i;
	for (int i = 0; i < m; i++) {
		cin >> pieces[i];
	}
}

void Solve() {
	int i, delta, mn = 1000;
	for (i = 0; i <= (m - n); i++) {
		delta = pieces[i + n - 1] - pieces[i];
		mn = min(mn, delta);
	}
	cout << mn << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	cin >> n >> m;
	LoadPieces();
	sort(pieces, (pieces + m));
	Solve();
	return 0;
}