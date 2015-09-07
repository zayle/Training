#include <fstream>
#include <iostream>
using namespace std;
// fstream fs("in.txt", fstream::in);

const int mx = 100;
int partitions[mx + 2];
bool numbers[mx + 1];
int w, p;

void LoadData() {
	int i;
	cin >> w >> p;
	partitions[0] = 0;
	for (i = 1; i <= p; i++) {
		cin >> partitions[i];
	}
	partitions[i] = w;
	numbers[w] = true;
}

void Solve() {
	int i, j;
	for (i = 0; i < (p + 2); i++) {
		for (j = (i + 1); j < (p + 2); j++) {
			numbers[partitions[j] - partitions[i]] = true;
		}
	}
	for (i = 1; i < w; i++) {
		if (numbers[i]) {
			cout << i << ' ';
		}
	}
	cout << w << '\n';
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