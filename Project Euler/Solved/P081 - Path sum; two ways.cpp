#include <fstream>
#include <iostream>
using namespace std;
fstream fs("P081 - Path sum: two ways.in.txt", fstream::in);

const int mx = 80;
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
	int i, j;
	for (i = 0; i < mx; i++) {
		for (j = 0; j < mx; j++) {
			if ((i > 0) && (j > 0)) {
				numbers[i][j] += min(numbers[i-1][j], numbers[i][j-1]);
			} else if (i > 0) {
				numbers[i][j] += numbers[i-1][j];
			} else if (j > 0) {
				numbers[i][j] += numbers[i][j-1];
			}
		}
	}
	cout << numbers[mx-1][mx-1] << '\n';
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
