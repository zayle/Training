#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

int w, s, x, y;
int workpieces[10000][100];
int cuts[100];

int LoadData() {
	int i, j, aux;
	cin >> w >> s >> x >> y;
	for (i = 0; i < w; i++) {
		for (j = 0; j < x; j++) {
			cin >> workpieces[i][j];
		}
	}
	for (i = 0; i < s; i++) {
		for (j = 0; j < x; j++) {
			cin >> aux;
			cuts[j] = max(cuts[j], aux);
		}
	}
}

void Solve() {
	int i, j;
	for (i = 0; i < w; i++) {
		cout << min(workpieces[i][0], (y - cuts[0]));
		for (j = 1; j < x; j++) {
			cout << ' ' << min(workpieces[i][j], (y - cuts[j]));
		}
		cout << '\n';
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	LoadData();
	Solve();
	return 0;
}