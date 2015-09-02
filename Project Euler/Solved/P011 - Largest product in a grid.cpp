#include <fstream>
#include <iostream>
using namespace std;
fstream fs("P011 - Largest product in a grid.in.txt", fstream::in);

const int mx = 20;
const int n = 4;
int numbers[mx][mx];

void LoadNumbers() {
	int i, j;
	for (i = 0; i < mx; i++) {
		for (j = 0; j < mx; j++) {
			fs >> numbers[i][j];
		}
	}
}

void Solve() {
	int i, j, k, p, maxP  = 0;
	for (i = 0; i < (mx - n); i++) {
		for (j = 0; j < (mx - n); j++) {
			p = 1;
			for (k = 0; k < n; k++) { p *= numbers[i][j + k]; }
			if (maxP < p) maxP = p;
			// ===== //
			p = 1;
			for (k = 0; k < n; k++) { p *= numbers[i + (n - 1)][j + k]; }
			if (maxP < p) maxP = p;
			// ===== //
			p = 1;
			for (k = 0; k < n; k++) { p *= numbers[i + k][j]; }
			if (maxP < p) maxP = p;
			// ===== //
			p = 1;
			for (k = 0; k < n; k++) { p *= numbers[i + k][j + (n - 1)]; }
			if (maxP < p) maxP = p;
			// ===== //
			p = 1;
			for (k = 0; k < n; k++) { p *= numbers[i + k][j + k]; }
			if (maxP < p) maxP = p;
			// ===== //
			p = 1;
			for (k = 0; k < n; k++) { p *= numbers[i + k][j + ((n - k) - 1)]; }
			if (maxP < p) maxP = p;
		}
	}
	cout << maxP << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int i, j;
	// ========== //
	LoadNumbers();
	Solve();
	return 0;
}