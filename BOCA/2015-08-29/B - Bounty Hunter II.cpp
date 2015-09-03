#include <fstream>
#include <iostream>
using namespace std;
fstream fs("in.txt", fstream::in);

const int mx = 1000;
int n, froms[mx], tos[mx];

void LoadData() {
	int from, j, k, to;
	fs >> n;
	for (from = 0; from < n; from++) {
		fs >> k;
		for (j = 0; j < k; j++) {
			fs >> to;
			froms[to]++;
			tos[from]++;
		}
	}
}

void Solve() {
	int i, count = 0;
	for (i = 0; i < n; i++) {
		if (froms[i] == 0) {
			count++;
		} else {
			count += max(0, (tos[i] - 1));
		}
	}
	cout << count << '\n';
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